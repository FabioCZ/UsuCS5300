#include <CodeGenerator.hpp>
#include <unordered_map>
#include "LVal.hpp"
#include "Register.hpp"
#include "Expr/Expr.hpp"
#include <memory>
#include <boost/algorithm/string.hpp>
#include <location.hh>

namespace FC
{
    std::shared_ptr<Code> Code::_code = nullptr;
    std::string Code::ArgFileOutName = "out.asm";

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
        if(e->GetType().name == "string")
        {
            lv.LValType = Data;
            lv.DataLabel = id;
        }
        else
        {
            lv.LValType = Global;
            lv.GlobalPointerOffset = inst->AllocateGlobalPointer(4);
        }
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
        return std::make_shared<Expr>(val,IntType());
    }

    const std::shared_ptr<Expr> ProcStringExpr(std::string val)
    {
        auto inst = Code::Inst();
        return std::make_shared<Expr>(val);
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
            return std::make_shared<Expr>(e);
        }
        else if(lval->LValType == Stack)
        {
            FC::Expr e(FC::Register::Allocate(), lval->Type);
            inst->_outFile << "\tlw " << e.GetRegister()->name << ", " << lval->StackPointerOffset << "($sp)" << std::endl;
            return std::make_shared<Expr>(e);
        }
        else if(lval->LValType == Global)
        {
            FC::Expr e(FC::Register::Allocate(), lval->Type);
            inst->_outFile << "\tlw " << e.GetRegister()->name << ", " << lval->GlobalPointerOffset << "($gp) #" << id << std::endl;
            return std::make_shared<Expr>(e);
        }
        else if(lval->LValType == Data)// data
        {
            FC::Expr e(FC::Register::Allocate(), lval->Type);
            inst->_outFile << "\tla " << e.GetRegister()->name << ", " << lval->DataLabel << std::endl;
            return std::make_shared<Expr>(e);
        }
        else
        {
            std::cout << "Internal compiler error with LValues" << std::endl;
            exit(1);
        }
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
            lv.LValType = Global;
            lv.Type = type;
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
        //std::cout << "Allocating new, at: " << _currGPOffset << " size: " << size << std::endl;
        int pt = _currGPOffset;
        _currGPOffset += size;
        return pt;
    }

    void Assignment(std::shared_ptr<LVal> lv, std::shared_ptr<Expr> e)
    {
        auto inst = Code::Inst();
        if(lv->LValType == Data || lv->LValType == Const)
        {
            std::cout << "Constants cannot be overwritten with assignment" << std::endl;
            exit(1);
        }

        if(e->GetExprType() == Str)
        {
            std::cout << "Strings cannot be assigned" << std::endl;
            exit(1);
        }

        std::string mem = lv->LValType == Stack ?
                          (std::to_string(lv->StackPointerOffset) + "($sp)") : (std::to_string(lv->GlobalPointerOffset) + "($gp)");

        //std::cout << "mem: " << mem << std::endl;
        std::string reg_name;
        if(e->GetExprType() == Int)
        {
            int val = e->GetVal();
            auto r = Register::Allocate();
            reg_name = r->name;
            inst->_outFile << "\tli " << reg_name << ", " << val << " # Expression to register load" << std::endl;
        }
        else
        {
            reg_name = e->GetRegister()->name;
        }
        inst->_outFile << "\tsw " << reg_name << ", " << mem << " #Storing " << lv->name << std::endl;

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

    void WriteExpr(std::shared_ptr<Expr> e)
    {
        auto inst = Code::Inst();
        int sysCallType = -1;
        auto typeName = e->GetType().name;
        //std::cout << "Type Name for print: " << typeName << std::endl;
        if(typeName == "integer" || typeName == "boolean")
            sysCallType = 1;
        else if(typeName == "char")
            sysCallType = 11;
        else if (typeName == "string")
            sysCallType = 4;
        if(sysCallType == 4)
        {
            //TODO
        }
        else
        {
            inst->_outFile << "\tli $v0, " << sysCallType << std::endl;
            inst->_outFile << "\tmove $a0, " << e->GetRegister()->name << std::endl;
            inst->_outFile << "\tsyscall #print" << std::endl;
        }
    }

    void ReadToLVal(std::shared_ptr<LVal> lv)
    {
        auto inst = Code::Inst();
        if(lv->Type.name != "integer" && lv->Type.name != "char")
        {
            std::cout << "Read statement can only be used with integers and characters" << std::endl;
            exit(1);
        }

        inst->_outFile << "\tli $v0, 5" << std::endl;
        inst->_outFile << "\tlsyscall #read" << std::endl;
        std::string mem = lv->LValType == Stack ?
                          (std::to_string(lv->StackPointerOffset) + "($sp)") : (std::to_string(lv->GlobalPointerOffset) + "($gp)");
        inst->_outFile << "\tsw $v0, " << mem << " #store read value to " << lv->name << std::endl;
    }

    const std::shared_ptr<Expr> ToChar(std::shared_ptr<Expr> e)
    {
        e->CastIntToChar();
        return e;
    }

    const std::shared_ptr<Expr> ToInt(std::shared_ptr<Expr> e)
    {
        e->CastCharToInt();
        return e;
    }

    const std::shared_ptr<Expr> ProcCharExpr(char val)
    {
        auto inst = Code::Inst();
        return std::make_shared<Expr>((int)val,CharType());
    }
}