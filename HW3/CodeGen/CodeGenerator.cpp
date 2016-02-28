#include <CodeGenerator.hpp>
#include <unordered_map>
#include "LVal.hpp"
#include "Register.hpp"
#include "Expr/Expr.hpp"
#include <memory>
#include <boost/algorithm/string.hpp>
#include <parser.hpp>
#include <location.hh>

namespace FC
{
    std::shared_ptr<Code> Code::_code = nullptr;

    std::shared_ptr<Code> Code::Inst()
    {
        if (FC::Code::_code == nullptr)
        {
            FC::Code::_code = std::make_shared<Code>();
        }
        return FC::Code::_code;
    }

    void AddMain()
    {
        auto inst = Code::Inst();
        std::cout << "Writing Main" << std::endl;
        inst->_outFile << "Test code";
        WriteConstData();
    }


    void AddConst(std::string id,  std::shared_ptr<Expr> e)
    {

        auto inst = Code::Inst();
        auto lvalRes = inst->LValues.find(id);
        if(lvalRes != inst->LValues.end())
        {
            std::cout << "Constant " << id << "has already been defined" << std::endl;
            exit(1);
        }

        LVal lv;
        lv.Type = e->GetType();
        lv.LValType = Data;
        lv.DataLabel = id;

        inst->LValues[id] = std::make_shared<LVal>(lv);

        if(e->GetExprType() == Reg)
        {
            std::cout << "Constant parsing error";
            exit(1);
        }

        inst->ConstData[id] = e;
    }

    const std::shared_ptr<Expr> ProcIntExpr(int val)
    {
        auto inst = Code::Inst();
        inst->Expressions.push_back(std::make_shared<Expr>(val,IntType()));
        return inst->Expressions.back();
    }

    const std::shared_ptr<Expr> ProcStringExpr(std::string val)
    {
        auto inst = Code::Inst();

        inst->Expressions.push_back(std::make_shared<Expr>(val));
        return inst->Expressions.back();
    }

    const std::shared_ptr<Expr> LValToExpr(std::shared_ptr<LVal> lv)
    {
        auto id = lv->name;
        auto inst = Code::Inst();
        auto lvalRes = inst->LValues.find(id);
        if(lvalRes == inst->LValues.end())
        {
            std::cout << "Internal Compiler error: Can't find lval '" << id << "'" <<  std::endl;
            exit(1);
        }
        auto lval = lvalRes->second;

        if(lval->LValType == Const)
        {
            FC::Expr e(lval->ConstValue, lval->Type);
            inst->Expressions.push_back(std::make_shared<Expr>(e));
        }
        else if(lval->LValType == Stack)
        {
            FC::Expr e(FC::Register::Allocate(), lval->Type);
            inst->_outFile << "\tlw " << e.GetRegister()->name << ", " << lval->StackPointerOffset << "($sp)" << std::endl;
            inst->Expressions.push_back(std::make_shared<Expr>(e));
        }
        else if(lval->LValType == Global)
        {
            FC::Expr e(FC::Register::Allocate(), lval->Type);
            inst->_outFile << "\tlw " << e.GetRegister()->name << ", " << lval->GlobalPointerOffset << "($gp)" << std::endl;
            inst->Expressions.push_back(std::make_shared<Expr>(e));

        }
        else // data
        {
            FC::Expr e(FC::Register::Allocate(), lval->Type);
            inst->_outFile << "\tla " << e.GetRegister()->name << ", " << lval->DataLabel << std::endl;
            inst->Expressions.push_back(std::make_shared<Expr>(e));
        }
        return inst->Expressions.back();
    }

    void WriteConstData()
    {
        auto inst = Code::Inst();
        inst->_outFile << ".data:" << std::endl;
        for(auto e : inst->ConstData)
        {
            inst->_outFile << "\t" << e.first << ": .dataType " << e.second->GetVal() << std::endl;
        }
    }

    Type SimpleTypeLookup(std::string typeName)
    {
        boost::algorithm::to_lower(typeName);
        if(typeName == std::string("integer"))
        {
            return IntType();
        }
        if(typeName == std::string("char"))
        {
            return CharType();
        }
        if(typeName == std::string("boolean"))
        {
            return BoolType();
        }
        std::cout << "Type: " << typeName << " is not a valid type" << std::endl;
        exit(1);
        return Type();
    }

    void AddIdent(std::string id)
    {
        //std::cout << "Ident " << id << " added to temp list" << std::endl;
        auto inst = Code::Inst();
        inst->TempIdentList.push_back(id);
    }

    void AddVariables(Type type)
    {
        auto inst = Code::Inst();
        if(inst->TempIdentList.size() == 0)
        {
            std::cout << "Internal error when initializing variables" << std::endl;
            exit(1);
        }
        for(auto a : inst->TempIdentList)
        {
            //std::cout << "adding var " << a << std::endl;
            LVal lv;
            lv.name = a;
            lv.GlobalPointerOffset = inst->AllocateGlobalPointer(type.size);
            inst->LValues[a] = std::make_shared<LVal>(lv);
        }

        inst->TempIdentList.clear();
    }


    int Code::AllocateStackPointer(int size)
    {
        _currSPOffset -= size;
        return _currSPOffset;
    }

    int Code::AllocateGlobalPointer(int size)
    {
        int pt = _currGPOffset;
        _currGPOffset += size;
        return pt;
    }

    void Assignment(std::shared_ptr<LVal> lv, std::shared_ptr<Expr> e)
    {

    }

    std::shared_ptr<LVal> GetLValForIdent(std::string id)
    {
        auto inst = Code::Inst();
        auto lvalRes = inst->LValues.find(id);
        if(lvalRes == inst->LValues.end())
        {
            std::cout << "Internal Compiler error: Can't find lval " << id << std::endl;
            exit(1);
        }
        return lvalRes->second;
    }


    const std::shared_ptr<Expr> ProcOrExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        auto res = Register::Allocate();
        inst->_outFile << "\tor " << res->name << ", " << l->GetRegister()->name << ", " << r->GetRegister()->name << std::endl;
        if(l->GetType().name != r->GetType().name)
        {
            static yy::location loc;
            std::cout << "Syntax Error: Expressions don't agree in type, line: " << loc << std::endl;
            exit(0);
        }
        return std::make_shared<Expr>(res, l->GetType());
    }

    const std::shared_ptr<Expr> ProcAndExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        auto res = Register::Allocate();
        inst->_outFile << "\tand " << res->name << ", " << l->GetRegister()->name << ", " << r->GetRegister()->name << std::endl;
        if(l->GetType().name != r->GetType().name)
        {
            static yy::location loc;
            std::cout << "Syntax Error: Expressions don't agree in type, line: " << loc << std::endl;
            exit(0);
        }
        return std::make_shared<Expr>(res, l->GetType());
    }

    const std::shared_ptr<Expr> ProcEqualExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {

    }
    const std::shared_ptr<Expr> ProcNotEqualExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        return std::shared_ptr<Expr>();
    }

    const std::shared_ptr<Expr> ProcLessEqualExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        return std::shared_ptr<Expr>();
    }


    const std::shared_ptr<Expr> ProcGreaterEqualExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        return std::shared_ptr<Expr>();
    }

    const std::shared_ptr<Expr> ProcLessThanExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        return std::shared_ptr<Expr>();
    }

    const std::shared_ptr<Expr> ProcGreaterThanExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        return std::shared_ptr<Expr>();
    }

    const std::shared_ptr<Expr> ProcPlusExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        auto res = Register::Allocate();
        inst->_outFile << "\tadd " << res->name << ", " << l->GetRegister()->name << ", " << r->GetRegister()->name << std::endl;
        if(l->GetType().name != r->GetType().name)
        {
            static yy::location loc;
            std::cout << "Syntax Error: Expressions don't agree in type, line: " << loc << std::endl;
            exit(0);
        }
        return std::make_shared<Expr>(res, l->GetType());
    }

    const std::shared_ptr<Expr> ProcMinusExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        auto res = Register::Allocate();
        inst->_outFile << "\tsub " << res->name << ", " << l->GetRegister()->name << ", " << r->GetRegister()->name << std::endl;
        if(l->GetType().name != r->GetType().name)
        {
            static yy::location loc;
            std::cout << "Syntax Error: Expressions don't agree in type, line: " << loc << std::endl;
            exit(0);
        }
        return std::make_shared<Expr>(res, l->GetType());
    }

    const std::shared_ptr<Expr> ProcDivideExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        auto res = Register::Allocate();
        inst->_outFile << "\tdiv " << res->name << ", " << l->GetRegister()->name << ", " << r->GetRegister()->name << std::endl;
        if(l->GetType().name != r->GetType().name)
        {
            static yy::location loc;
            std::cout << "Syntax Error: Expressions don't agree in type, line: " << loc << std::endl;
            exit(0);
        }
        return std::make_shared<Expr>(res, l->GetType());
    }

    const std::shared_ptr<Expr> ProcMultiplyExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        auto res = Register::Allocate();
        inst->_outFile << "\tmul " << res->name << ", " << l->GetRegister()->name << ", " << r->GetRegister()->name << std::endl;
        if(l->GetType().name != r->GetType().name)
        {
            static yy::location loc;
            std::cout << "Syntax Error: Expressions don't agree in type, line: " << loc << std::endl;
            exit(0);
        }
        return std::make_shared<Expr>(res, l->GetType());
    }

    const std::shared_ptr<Expr> ProcModExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        auto res = Register::Allocate();
        inst->_outFile << "\tmod " << res->name << ", " << l->GetRegister()->name << ", " << r->GetRegister()->name << std::endl;
        if(l->GetType().name != r->GetType().name)
        {
            static yy::location loc;
            std::cout << "Syntax Error: Expressions don't agree in type, line: " << loc << std::endl;
            exit(0);
        }
        return std::make_shared<Expr>(res, l->GetType());
    }

    const std::shared_ptr<Expr> ProcNotExpr(std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        inst->_outFile << "\tnot " << r->GetRegister()->name << ", " << r->GetRegister()->name << std::endl;
        return r;
    }

    const std::shared_ptr<Expr> ProcUnaryMinusExpr(std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        inst->_outFile << "\tsub " << r->GetRegister()->name << ", $zero, " << r->GetRegister()->name << std::endl;
        return r;
    }
}