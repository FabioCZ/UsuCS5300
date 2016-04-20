/*
 * Fabio Gottlicher's CPSL Compiler
 * A01647928
 * Created for USU CS5300 - Compiler Construction, Spring 2016
 */

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
            FC::Code::_code->InMain = true;
            _code->_stream << ".global main" << std::endl;

            LVal t;
            t.LValType = Const;
            t.ConstValue = 1;
            t.Type = BoolType();
            t.name = "true";
            _code->LValues["true"] = std::make_shared<LVal>(t);

            LVal t1;
            t1.LValType = Const;
            t1.ConstValue = 1;
            t1.Type = BoolType();
            t1.name = "TRUE";
            _code->LValues["TRUE"] = std::make_shared<LVal>(t1);

            LVal f;
            f.LValType = Const;
            f.ConstValue = 0;
            f.Type = BoolType();
            f.name = "false";
            _code->LValues["false"] = std::make_shared<LVal>(f);

            LVal f1;
            f1.LValType = Const;
            f1.ConstValue = 0;
            f1.Type = BoolType();
            f1.name = "FALSE";
            _code->LValues["FALSE"] = std::make_shared<LVal>(f1);

            //Add predefined types
            _code->Types.emplace("integer",IntType());
            _code->Types.emplace("char",CharType());
            _code->Types.emplace("boolean",BoolType());

            _code->WriteToFileNow();
        }
        return FC::Code::_code;
    }

    void Code::WriteToFileNow()
    {
        _outFile << _stream.str();
        _stream.str(std::string()); //clear the stream
    }

    void AddMain()
    {
        auto inst = Code::Inst();
        Stop(); //Add stop stament
        inst->_stream << "#Finished writing maing, now writing data sector" << std::endl;
        WriteConstData();
        inst->WriteToFileNow();
    }

    void MainBlock()
    {
        auto inst = Code::Inst();
        inst->InMain = true;
        //inst->WriteToFileNow();
        inst->_stream << "main_impl:" << std::endl;
    }

    void FuncBlock()
    {
        auto inst = Code::Inst();
        inst->WriteToFileNow();
        inst->_outFile << "j main_impl #jumping into main" << std::endl;
        inst->InMain = false;
    }



    void AddConst(std::string id,  std::shared_ptr<Expr> e)
    {

        auto inst = Code::Inst();
        if(inst->InMain)
        {
            auto lvalRes = inst->LValues.find(id);
            if (lvalRes != inst->LValues.end())
            {
                std::cout << "Constant " << id << "has already been defined" << std::endl;
                exit(1);
            }

            LVal lv;
            lv.Type = e->GetType();
            lv.name = id;
            if (e->GetType().name == "string")
            {
                //std::cout << "adding const " << id << std::endl;
                lv.LValType = Data;
                lv.DataLabel = id;
                inst->ConstData[id] = e;
            }
            else if(e->GetExprType() == Int)
            {
                lv.LValType = Const;
                lv.ConstValue = e->GetVal();
            }
            else
            {
                lv.LValType = Global;
                lv.GlobalPointerOffset = inst->AllocateGlobalPointer(4);
                std::string reg_name = e->GetRegister()->name;
                inst->_stream << "\tsw " << reg_name << ", " << lv.GlobalPointerOffset << "($gp) #Storing " <<
                lv.name << std::endl;
            }
            inst->LValues[id] = std::make_shared<LVal>(lv);
        }
        else    //CONST in func body
        {
            auto l = inst->LocalLValues.find(id);
            if(l != inst->LocalLValues.end())
            {
                l = inst->LValues.find(id);
                if (l != inst->LValues.end())
                {
                    std::cout << "Constant " << id << "has already been defined" << std::endl;
                    exit(1);
                }
            }

            LVal lv;
            lv.Type = e->GetType();
            lv.name = id;
            if (e->GetType().name == "string")
            {
                //std::cout << "adding const " << id << std::endl;
                lv.LValType = Data;
                lv.DataLabel = id;
                inst->ConstData[id] = e;
            }
            else
            {
                lv.LValType = Global;
                lv.GlobalPointerOffset = inst->AllocateGlobalPointer(4);
                std::string reg_name = e->GetRegister()->name;
                //local constants sit on the global pointer. oh well.
                inst->_stream << "\tsw " << reg_name << ", " << lv.GlobalPointerOffset << "($gp) #Storing " << lv.name << std::endl;
            }
            inst->LocalLValues[id] = std::make_shared<LVal>(lv);
        }

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
        std::shared_ptr<LVal> lval = lv;

        if(lv->name == "_return2")  //This is so bad I don't even know where to begin
        {
            lval = lv;
        }

        if(lval->Type.isArray || lval->Type.isRecord) // array (not member) or Record (not field)
        {
            auto e = std::make_shared<FC::Expr>(Register::Allocate(),lv->Type);    //save base address as expression
            if (lval->LValType == Frame)
            {
                inst->_stream << "\taddi " << e->GetRegister()->name << ", $fp, " << lval->FramePointerOffset << std::endl;
            }
            else if (lval->LValType == Stack)
            {
                inst->_stream << "\taddi " << e->GetRegister()->name << ", $sp, " << lval->StackPointerOffset << std::endl;
            }
            else if (lval->LValType == Global)
            {
                inst->_stream << "\taddi " << e->GetRegister()->name << ", $gp, " << lval->GlobalPointerOffset << std::endl;
            }
            return e;
        }

        //Special handling if we have an array member
        if(lval->isArrayMember)
        {
            auto e = std::make_shared<FC::Expr>(FC::Register::Allocate(),lval->Type);
            auto address = std::make_shared<FC::Expr>(FC::Register::Allocate(),IntType());
            auto helper = std::make_shared<FC::Expr>(FC::Register::Allocate(),IntType());
            inst->_stream << "\tli " << address->GetRegister()->name << ", " << lval->Type.size << " #array type size"<< std::endl;
            inst->_stream << "\tli " << helper->GetRegister()->name << ", " << lval->arrLowStart << " #array starting index" << std::endl;
            inst->_stream << "\tsub " << helper->GetRegister()->name << ", " << lval->arrExpr->GetRegister()->name << ", " << helper->GetRegister()->name<< " #calculate index" << std::endl;
            inst->_stream << "\tmul " << address->GetRegister()->name << ", " << helper->GetRegister()->name << ", " << address->GetRegister()->name << " #offset from base of array" << std::endl;
            if(lval->LValType == Frame)
            {
                inst->_stream << "\taddi " << address->GetRegister()->name << ", " << address->GetRegister()->name << ", " << lval->FramePointerOffset << " #offset from pointer (f/s/g)" << std::endl;
                inst->_stream << "\tadd " << address->GetRegister()->name << ", " << address->GetRegister()->name << ", $fp #adding fp offset and fp" << std::endl;
            }
            else if(lval->LValType == Stack)
            {
                inst->_stream << "\taddi " << address->GetRegister()->name << ", " << address->GetRegister()->name << ", " << lval->StackPointerOffset << " #offset from pointer (f/s/g)" << std::endl;
                inst->_stream << "\tadd " << address->GetRegister()->name << ", " << address->GetRegister()->name << ", $sp #adding sp offset and sp" << std::endl;
            }
            else if(lval->LValType == Global)
            {
                inst->_stream << "\taddi " << address->GetRegister()->name << ", " << address->GetRegister()->name << ", " << lval->GlobalPointerOffset << " #offset from pointer (f/s/g)" << std::endl;
                inst->_stream << "\tadd " << address->GetRegister()->name << ", " << address->GetRegister()->name << ", $gp #adding gp offset and gp" << std::endl;
            }
            inst->_stream << "\tlw " << e->GetRegister()->name << ", 0("<< address->GetRegister()->name << ")" << " #loading array elem into register" << std::endl;
            return e;
        }

        if(lval->LValType == Const)
        {
            FC::Expr e(lval->ConstValue, lval->Type);
            return std::make_shared<Expr>(e);
        }
        else if(lval->LValType == Stack)
        {
            FC::Expr e(FC::Register::Allocate(), lval->Type);
            inst->_stream << "\tlw " << e.GetRegister()->name << ", " << lval->StackPointerOffset << "($sp)" << std::endl;
            return std::make_shared<Expr>(e);
        }
        else if(lval->LValType == Frame)
        {
            if(lval->name == "_return2")
            {
                FC::Expr e(FC::Register::AllocateCustom("$t0"), lval->Type);
                inst->_stream << "\tlw " << e.GetCustomRegister("$t0")->name << ", " << lval->FramePointerOffset << "($fp)" << std::endl;
                return std::make_shared<Expr>(e);
            }
            else
            {
                FC::Expr e(FC::Register::Allocate(), lval->Type);
                inst->_stream << "\tlw " << e.GetRegister()->name << ", " << lval->FramePointerOffset << "($fp)" << std::endl;
                return std::make_shared<Expr>(e);
            }
        }
        else if(lval->LValType == Global)
        {
            FC::Expr e(FC::Register::Allocate(), lval->Type);
            inst->_stream << "\tlw " << e.GetRegister()->name << ", " << lval->GlobalPointerOffset << "($gp) #" << id << std::endl;
            return std::make_shared<Expr>(e);
        }
        else if(lval->LValType == Data)// data
        {
            FC::Expr e(FC::Register::Allocate(), lval->Type);
            inst->_stream << "\tla " << e.GetRegister()->name << ", " << lval->DataLabel << std::endl;
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
        inst->_stream << ".data:" << std::endl;
        for(auto e : inst->ConstData)
        {
            if(e.second->GetType().name == "string")
                inst->_stream << "\t" << e.first << ": .asciiz \"" << e.second->GetStringVal().c_str() << "\"" << std::endl;
            else if(e.second->GetType().name == "integer")
                inst->_stream << "\t" << e.first << ": .word " << e.second->GetVal() << std::endl;

        }
    }

    Type SimpleTypeLookup(std::string typeName)
    {
        boost::algorithm::to_lower(typeName);   //just in case

        auto inst = Code::Inst();
        //auto res = std::find(inst->Types.begin(),inst->Types.end(),typeName);
        auto res = inst->Types.find(typeName);
        if(res == inst->Types.end())
        {
            std::cout << "Type: " << typeName << " is not a valid type" << std::endl;
            exit(1);
        }
        return (*res).second;
    }

    void AddIdent(std::string id)
    {
        auto inst = Code::Inst();
        if(inst->InMain)
        {
            inst->TempIdentList.push_back(id);
        }
        else // temp ident list in function
        {
            inst->LocalTempIdentList.push_back(id);
        }
    }

    void AddVariables(Type type)
    {
        auto inst = Code::Inst();
        if(inst->InMain)
        {
            if (inst->TempIdentList.size() == 0)
            {
                std::cout << "Internal error when initializing variables" << std::endl;
                exit(1);
            }
            for (auto a : inst->TempIdentList)
            {
                if (inst->LValues.find(a) != inst->LValues.end())
                {
                    std::cout << "Syntax error: identifier " << a << " has already been defined" << std::endl;
                    exit(1);
                }
                LVal lv;
                lv.name = a;
                lv.LValType = Global;
                lv.Type = type;
                lv.GlobalPointerOffset = inst->AllocateGlobalPointer(type.size);
                inst->LValues[a] = std::make_shared<LVal>(lv);
            }

            inst->TempIdentList.clear();
        }
        else    //vars in function
        {
            inst->_stream << "# adding vars in function!" << std::endl;
            if (inst->LocalTempIdentList.size() == 0)
            {
                std::cout << "Internal error when initializing variables" << std::endl;
                exit(1);
            }
            for (auto a : inst->LocalTempIdentList)
            {
                if (inst->LocalLValues.find(a) != inst->LocalLValues.end())
                {
                    std::cout << "Syntax error: identifier " << a << " has already been defined" << std::endl;
                    exit(1);
                }
                LVal lv;
                lv.name = a;
                lv.LValType = Stack;
                lv.Type = type;
                lv.StackPointerOffset = inst->AllocateStackPointer(type.size); //TODO figure out if this will work
                inst->LocalLValues[a] = std::make_shared<LVal>(lv);
            }

            inst->LocalTempIdentList.clear();
        }
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

    int Code::addLabelNumber()
    {
        auto toRet = ++_labelCounter;
        _labelNumbers.push_back(toRet);
        _elseLabels[toRet] = 0;
        return toRet;
    }

    int Code::getCurrLabelNumber()
    {
        return _labelNumbers.back();
    }

    int Code::dropLabelNumber()
    {
        auto toRet = _labelNumbers.back();
        _labelNumbers.pop_back();
        _elseLabels.erase(toRet);
        return toRet;
    }

    int Code::incrElseCount()
    {
        return ++_elseLabels[_labelNumbers.back()];
    }

    int Code::getElseCount()
    {
        return _elseLabels[_labelNumbers.back()];
    }


    void Assignment(std::shared_ptr<LVal> lv, std::shared_ptr<Expr> e)
    {
        auto inst = Code::Inst();
        if(lv->LValType == Data || lv->LValType == Const)
        {
            std::cout << "Constants cannot be overwritten with assignment" << std::endl;
            exit(1);
        }

        if(e == nullptr)
        {
            std::cout << "oops. expression is null" << std::endl;
            exit(1);
        }


        if(e->GetExprType() == Str)
        {
            std::cout << "Strings cannot be assigned" << std::endl;
            exit(1);
        }

        std::string mem = "";
        std::string reg_name = e->GetRegister()->name;

        if(lv->isArrayMember)
        {
            auto lval = lv;
            auto address = std::make_shared<FC::Expr>(FC::Register::Allocate(),IntType());
            auto helper = std::make_shared<FC::Expr>(FC::Register::Allocate(),IntType());
            inst->_stream << "\tli " << address->GetRegister()->name << ", " << lval->Type.size << " #array type size"<< std::endl;
            inst->_stream << "\tli " << helper->GetRegister()->name << ", " << lval->arrLowStart << " #array starting index" << std::endl;
            inst->_stream << "\tsub " << helper->GetRegister()->name << ", " << lval->arrExpr->GetRegister()->name << ", " << helper->GetRegister()->name << " #calculate index" << std::endl;
            inst->_stream << "\tmul " << address->GetRegister()->name << ", " << helper->GetRegister()->name << ", " << address->GetRegister()->name << " #offset from base of array" << std::endl;
            if (lv->LValType == Stack)
            {
                inst->_stream << "\taddi " << address->GetRegister()->name << ", " << address->GetRegister()->name << ", " << lval->StackPointerOffset << " #offset from pointer (f/s/g)" << std::endl;
                inst->_stream << "\tadd " << address->GetRegister()->name << ", " << address->GetRegister()->name << ", $sp" << std::endl;
            }
            else if (lv->LValType == Global)
            {
                inst->_stream << "\taddi " << address->GetRegister()->name << ", " << address->GetRegister()->name << ", " << lval->GlobalPointerOffset << " #offset from pointer (f/s/g)" << std::endl;
                inst->_stream << "\tadd " << address->GetRegister()->name << ", " << address->GetRegister()->name << ", $gp" << std::endl;

            }
            else if (lv->LValType == Frame)
            {
                inst->_stream << "\taddi " << address->GetRegister()->name << ", " << address->GetRegister()->name << ", " << lval->FramePointerOffset << " #offset from pointer (f/s/g)" << std::endl;
                inst->_stream << "\tadd " << address->GetRegister()->name << ", " << address->GetRegister()->name << ", $fp" << std::endl;
            }
            else
            {
                std::cout << "Internal assignment statement error" << std::endl;
                exit(0);
            }
            mem = std::string("0(") + address->GetRegister()->name + ")";
            inst->_stream << "\tsw " << reg_name << ", " << mem << " #Storing " << lv->name << std::endl;

        }
        else
        {
            //std::cout << "assignemnt for type: " << e->GetType().name << " into: " << lv->name << std::endl;
            if(e->GetType().isArray || e->GetType().isRecord)
            {
                auto helper = std::make_shared<FC::Expr>(FC::Register::Allocate(),IntType());
                for(int i = 0; i < lv->Type.size;i+=4)
                {
                    if (lv->LValType == Stack)
                    {
                        mem = std::to_string(lv->StackPointerOffset + i) + "($sp)";
                    }
                    else if (lv->LValType == Global)
                    {
                        mem = std::to_string(lv->GlobalPointerOffset + i) + "($gp)";
                    }
                    else if (lv->LValType == Frame)
                    {
                        mem = std::to_string(lv->FramePointerOffset + i) + "($fp)";
                    }
                    else
                    {
                        std::cout << "Internal assignment statement error" << std::endl;
                        exit(0);
                    }
                    inst->_stream << "\tlw " << helper->GetRegister()->name << ", "<< i <<  "(" << e->GetRegister()->name << ") #memberwise clone" << std::endl;
                    inst->_stream << "\tsw " << helper->GetRegister()->name << ", " << mem << std::endl;
                }
            }
            else
            {

                if (lv->LValType == Stack)
                {
                    mem = std::to_string(lv->StackPointerOffset) + "($sp)";
                }
                else if (lv->LValType == Global)
                {
                    mem = std::to_string(lv->GlobalPointerOffset) + "($gp)";
                }
                else if (lv->LValType == Frame)
                {
                    mem = std::to_string(lv->FramePointerOffset) + "($fp)";
                }
                else
                {
                    std::cout << "Internal assignment statement error" << std::endl;
                    exit(0);
                }
                inst->_stream << "\tsw " << reg_name << ", " << mem << " #Storing " << lv->name << std::endl;
            }
        }
    }

    std::shared_ptr<LVal> GetLValForIdent(std::string id)
    {
        auto inst = Code::Inst();
        std::shared_ptr<LVal> lval = nullptr;
        if(!inst->InMain)
        {

            auto l = inst->LocalLValues.find(id);
            if(l != inst->LocalLValues.end())
            {
                lval = l->second;
            }
        }

        if(lval == nullptr)
        {
            auto l = inst->LValues.find(id);
            if(l != inst->LValues.end())
            {
                lval = l->second;
            }
        }
        if(lval == nullptr)
        {
            std::cout << "Error:The Lvalue " << id << " has not been defined" << std::endl;
            exit(0);
        }
        return lval;
    }


    const std::shared_ptr<Expr> ProcBinaryExpr(std::string opName, std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        auto res = Register::Allocate();
        inst->_stream << "\t" << opName << " " << res->name << ", " << l->GetRegister()->name << ", " << r->GetRegister()->name << std::endl;
//        if(l->GetType().name != "char" && r->GetType().name != "integer")
//        {
//            std::cout << "Syntax Error: Expressions don't agree in type, l:" << l->GetType().name << ", r: " <<  r->GetType().name << std::endl;
//            exit(0);
//        }
        return std::make_shared<Expr>(res, l->GetType());
    }

    const std::shared_ptr<Expr> ProcOrExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        return ProcBinaryExpr("or",l,r);
    }

    const std::shared_ptr<Expr> ProcAndExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        return ProcBinaryExpr("and",l,r);
    }

    const std::shared_ptr<Expr> ProcEqualExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        return ProcBinaryExpr("seq",l,r);
    }
    const std::shared_ptr<Expr> ProcNotEqualExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        return ProcBinaryExpr("sne",l,r);
    }

    const std::shared_ptr<Expr> ProcLessEqualExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        return ProcBinaryExpr("sle",l,r);
    }


    const std::shared_ptr<Expr> ProcGreaterEqualExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        return ProcBinaryExpr("sle",r,l);
    }

    const std::shared_ptr<Expr> ProcLessThanExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        return ProcBinaryExpr("slt",l,r);
    }

    const std::shared_ptr<Expr> ProcGreaterThanExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        return ProcBinaryExpr("slt",r,l);
    }

    const std::shared_ptr<Expr> ProcPlusExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        if(l->GetExprType() == Int && r->GetExprType() == Int) //if both are int const, we can precompile
        {
            auto res = l->GetVal() + r->GetVal();
            return std::make_shared<Expr>(res,l->GetType());
        }
        else
        {
            auto res = Register::Allocate();
            inst->_stream << "\tadd " << res->name << ", " << l->GetRegister()->name << ", " <<
            r->GetRegister()->name << std::endl;
            return std::make_shared<Expr>(res, l->GetType());
        }
    }

    const std::shared_ptr<Expr> ProcMinusExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        if(l->GetExprType() == Int && r->GetExprType() == Int) //if both are int const, we can precompile
        {
            auto res = l->GetVal() - r->GetVal();
            return std::make_shared<Expr>(res,l->GetType());
        }
        else
        {
            auto res = Register::Allocate();
            inst->_stream << "\tsub " << res->name << ", " << l->GetRegister()->name << ", " <<
            r->GetRegister()->name << std::endl;
            return std::make_shared<Expr>(res, l->GetType());
        }
    }

    const std::shared_ptr<Expr> ProcDivideExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        if(l->GetExprType() == Int && r->GetExprType() == Int) //if both are int const, we can precompile
        {
            auto res = l->GetVal() / r->GetVal();
            return std::make_shared<Expr>(res,l->GetType());
        }
        else
        {
            auto res = Register::Allocate();
            inst->_stream << "\tdiv " << res->name << ", " << l->GetRegister()->name << ", " <<
            r->GetRegister()->name << std::endl;
            return std::make_shared<Expr>(res, l->GetType());
        }
    }

    const std::shared_ptr<Expr> ProcMultiplyExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        if(l->GetExprType() == Int && r->GetExprType() == Int) //if both are int const, we can precompile
        {
            auto res = l->GetVal() * r->GetVal();
            return std::make_shared<Expr>(res,l->GetType());
        }
        else
        {
            auto res = Register::Allocate();
            inst->_stream << "\tmul " << res->name << ", " << l->GetRegister()->name << ", " <<
            r->GetRegister()->name << std::endl;
            return std::make_shared<Expr>(res, l->GetType());
        }
    }

    const std::shared_ptr<Expr> ProcModExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        if(l->GetExprType() == Int && r->GetExprType() == Int) //if both are int const, we can precompile
        {
            auto res = l->GetVal() + r->GetVal();
            return std::make_shared<Expr>(res,l->GetType());
        }
        else
        {
            auto res = Register::Allocate();
            inst->_stream << "\trem " << res->name << ", " << l->GetRegister()->name << ", " <<
            r->GetRegister()->name << std::endl;
            return std::make_shared<Expr>(res, l->GetType());
        }
    }

    const std::shared_ptr<Expr> ProcNotExpr(std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        inst->_stream << "\tnot " << r->GetRegister()->name << ", " << r->GetRegister()->name << std::endl;
        return r;
    }

    const std::shared_ptr<Expr> ProcUnaryMinusExpr(std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        if(r->GetExprType() == Int ) //if expr is int const, we can precompile
        {
            auto res = r->GetVal() * -1;
            return std::make_shared<Expr>(res,r->GetType());
        }
        else
        {
            inst->_stream << "\tsub " << r->GetRegister()->name << ", $zero, " << r->GetRegister()->name << std::endl;
            return r;
        }
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
        {
            if(e->GetExprType() == Str)
            {
                auto label = inst->GetNextStringDataLabel();

                //std::cout << e->GetStringVal() << " string type" << std::endl;
                AddConst(label, std::make_shared<Expr>(e->GetStringVal())); // this is bad, but it works
                std::shared_ptr<LVal> lv = GetLValForIdent(label);
                auto ex = LValToExpr(lv);
                e = ex;
            }
            sysCallType = 4;
        }
        else
        {
            std::cout << "trying to print unknown type" << std::endl;
            exit(0);
        }
//        if(sysCallType == 4)
//        {
//            //TODO
//        }
//        else
//        {
            inst->_stream << "\tli $v0, " << sysCallType << std::endl;
            inst->_stream << "\tmove $a0, " << e->GetRegister()->name << std::endl;
            inst->_stream << "\tsyscall #print" << std::endl;
//        }
    }

    void ReadToLVal(std::shared_ptr<LVal> lv)
    {
        auto inst = Code::Inst();
        if(lv->Type.name != "integer" && lv->Type.name != "char")
        {
            std::cout << "Read statement can only be used with integers and characters" << std::endl;
            exit(1);
        }

        int syscallType = lv->Type.name == "integer" ? 5 : 12;

        inst->_stream << "\tli $v0, " << syscallType << std::endl;
        inst->_stream << "\tsyscall #read" << std::endl;
        std::string mem = lv->LValType == Stack ?
                          (std::to_string(lv->StackPointerOffset) + "($sp)") : (std::to_string(lv->GlobalPointerOffset) + "($gp)");
        inst->_stream << "\tsw $v0, " << mem << " #store read value to " << lv->name << std::endl;
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
        return std::make_shared<Expr>((int)val,CharType());
    }

    void  Stop()
    {
        auto inst = Code::Inst();
        inst->_stream << "\tli $v0, 10 #load stop instr" << std::endl;
        inst->_stream << "\tsyscall" << std::endl;
    }

    const std::shared_ptr<Expr> ProcDecrement(std::shared_ptr<Expr> e)
    {
        auto typeName = e->GetType().name;
        if(typeName != "integer" && typeName != "boolean" && typeName != "char")
        {
            std::cout << "Pred is only defined for integers, booleans and chars";
            exit(1);
        }

        if(typeName == "boolean")
        {
            return ProcNotExpr(e);
        }
        else
        {
            auto inst = Code::Inst();
            inst->_stream << "\taddi " << e->GetRegister()->name << ", " << e->GetRegister()->name << ", -1 #decrement" << std::endl;
            return e;
        }
    }

    const std::shared_ptr<Expr> ProcIncrement(std::shared_ptr<Expr> e)
    {
        auto typeName = e->GetType().name;
        if(typeName != "integer" && typeName != "boolean" && typeName != "char")
        {
            std::cout << "Succ is only defined for integers, booleans and chars";
            exit(1);
        }

        if(typeName == "boolean")
        {
            return ProcNotExpr(e);
        }
        else
        {
            auto inst = Code::Inst();
            auto regName = e->GetRegister()->name;
            inst->_stream << "\taddi " << regName << ", " << regName << ", 1 #increment" << std::endl;
           // std::cout << e->GetExprType() << " expr type " << e->GetType().name << " type   " << std::endl;
            return e;
        }
    }

    void WriteStatement()
    {
        Code::Inst()->WriteToFileNow();
    }

    void WhileSuperHead()
    {
        Code::Inst()->WriteToFileNow();
        auto inst = Code::Inst();
        inst->_stream << "WhileBegin" << inst->addLabelNumber() << ":" << std::endl;
    }

    void WhileHead(std::shared_ptr<Expr> e)
    {
        auto inst = Code::Inst();
        //inst->WriteToFileNow();
        inst->_stream << "\tbeq $zero," << e->GetRegister()->name << ", WhileEnd" << inst->getCurrLabelNumber() << std::endl;
    }


    void WhileEnd()
    {
        auto inst = Code::Inst();
        //inst->WriteToFileNow();
        auto labelNum = inst->dropLabelNumber();
        inst->_stream << "\tj WhileBegin" << labelNum << std::endl;
        inst->_stream << "\tWhileEnd"<< labelNum << ":" << std::endl;
    }

    void RepeatHead()
    {
        auto inst = Code::Inst();
        //inst->WriteToFileNow();
        inst->_stream << "RepeatBegin" << inst->addLabelNumber() << ":" << std::endl;

    }

    void RepeatEnd(std::shared_ptr<Expr> e)
    {
        auto inst = Code::Inst();
        //inst->WriteToFileNow();
        inst->_stream << "\tbeq $zero," << e->GetRegister()->name << ", RepeatBegin" << inst->dropLabelNumber() << std::endl;
    }

    void IfHead(std::shared_ptr<Expr> e)
    {
        auto inst = Code::Inst();
        //inst->WriteToFileNow();
        inst->_stream << "\t beq $zero, " << e->GetRegister()->name << ", ElseLabel" << inst->incrElseCount() << "_" << inst->addLabelNumber() << " #if/else jump" << std::endl;
    }

    void ElseIfSuperHead()
    {
        auto inst = Code::Inst();
        auto elseLabel = inst->getElseCount();
        //inst->WriteToFileNow();
        inst->_stream << "j ElseLabelEnd" << "_" << inst->getCurrLabelNumber() << " #jump to after else" << std::endl;
        inst->_stream << "ElseLabel" << elseLabel << "_" << inst->getCurrLabelNumber() << ": #else label" << std::endl;
    }


    void ElseIfHead(std::shared_ptr<Expr> e)
    {
        auto inst = Code::Inst();
        //inst->WriteToFileNow();
        inst->_stream<< "\t beq $zero, " << e->GetRegister()->name << ", ElseLabel" << inst->incrElseCount() << "_" << inst->getCurrLabelNumber() << " #if/else jump" << std::endl;
    }

    void ElseHead()
    {
        auto inst = Code::Inst();
        auto elseLabel = inst->getElseCount();
        //inst->WriteToFileNow();
        inst->_stream << "j ElseLabelEnd" << "_" << inst->getCurrLabelNumber() << " #jump to after else" << std::endl;
        inst->_stream << "ElseLabel" << elseLabel << "_" << inst->getCurrLabelNumber() << ": #else label" << std::endl;
    }

    void IfEnd()
    {
        auto inst = Code::Inst();
        //inst->WriteToFileNow();
        inst->_stream << "ElseLabelEnd" << "_" << inst->dropLabelNumber() << ":" << std::endl;
    }

    void ForHead(std::string s, std::shared_ptr<Expr> e)
    {
        //std::cout << "ForHead" << std::endl;
        auto inst = Code::Inst();
        AddIdent(s);
        AddVariables(IntType());
        ProcIncrement(e);   //this makes for loops inclusive
        Assignment(GetLValForIdent(s),e);
        inst->WriteToFileNow();
        auto f = std::make_shared<ForInfo>(s,true);
        inst->ForInfos.emplace_back(f);
    }

    void ToHead(bool isUp, std::shared_ptr<Expr> e)
    {
        //std::cout << "Tohead" << isUp << std::endl;
        auto inst = Code::Inst();
        //inst->WriteToFileNow();
        inst->_stream << "ForStart" << inst->addLabelNumber() << ":" << std::endl;
        auto fi = inst->ForInfos.back()->varName;
        inst->ForInfos.pop_back();
        inst->ForInfos.push_back(std::make_shared<ForInfo>(fi,isUp));
        auto name = inst->ForInfos.back()->varName;
        auto e2 = std::const_pointer_cast<Expr>(LValToExpr(GetLValForIdent(name)))->GetRegister();
        auto e1 = e->GetRegister();
        if(isUp)
        {
            inst->_stream << "\tbgt " << e1->name << ", " << e2->name << ", ForEnd" << inst->getCurrLabelNumber() <<
            std::endl;
        }
        else
        {
            inst->_stream << "\tblt " << e1->name << ", " << e2->name << ", ForEnd" << inst->getCurrLabelNumber() <<
            std::endl;
        }
    }

    void ForEnd()
    {
        //std::cout << "forend" << std::endl;
        auto inst = Code::Inst();
        //inst->WriteToFileNow();
        auto forInfo = inst->ForInfos.back();
        inst->ForInfos.pop_back();
        auto lv = GetLValForIdent(forInfo->varName);
        if(forInfo->isUp)
        {
            Assignment(lv,ProcIncrement(LValToExpr(lv)));
        }
        else
        {
            Assignment(lv,ProcDecrement(LValToExpr(lv)));

        }
        //inst->WriteToFileNow();
        inst->_stream << "\tj ForStart" << inst->getCurrLabelNumber() << std::endl;
        inst->_stream << "ForEnd" << inst->dropLabelNumber() << ":" << std::endl;

        inst->LValues.erase(forInfo->varName);
    }

    const std::shared_ptr<Expr> CallFunction(std::string name, std::shared_ptr<std::vector<std::shared_ptr<Expr>>> args)
    {
        auto inst = Code::Inst();
        auto func = inst->Functions.find(name);
        if(func == inst->Functions.end())
        {
            std::cout << "Cannot find function: " << name << std::endl;
            exit(0);
        }

        if(args != nullptr && func->second->params != nullptr)
        {
            if ((*args).size() != func->second->params->size())
            {
                std::cout << "The provided number of arguments in proc/func call for " << func->first <<
                " was incorrect" << std::endl;
                exit(0);
            }
            for (int i = 0; i < (*args).size(); i++)
            {
                auto arg = (*args)[i]->GetType();
                auto f = (*func->second->params)[i].second;
                if (arg.size != f.size || arg.name != f.name)
                {
                    std::cout << "One of the provided arguments in proc/func call for " << func->first <<
                    " was incorrect" << std::endl;
                    exit(0);
                }
            }
        }
        else if (args == nullptr && func->second->params != nullptr ||
                args != nullptr && func->second->params == nullptr)
        {
            std::cout << "The provided number of arguments in proc/func call for " << func->first <<
            " was incorrect" << std::endl;
            exit(0);
        }

        //spill registers
        std::vector<std::string> toSpill = Register::getUsed();

        inst->_stream << "\taddi $sp, $sp, -" << (toSpill.size()*4 + 8) << " #spilling registers" << std::endl;
        inst->_stream << "\tsw $fp, 0($sp) # saving frame pointer" << std::endl;
        inst->_stream << "\tsw $ra, 4($sp) # saving return address" << std::endl;

        for(int i = 0; i < toSpill.size();i++)
        {
            inst->_stream << "\tsw " << toSpill[i] << ", " << (i*4 + 8) << "($sp)" << std::endl;
        }

        //std::cout << "calling func" << std::endl;
        //args
        //TODO make this work for custom types/arrays
        if(args != nullptr)
        {
            int argSize = 0;
            for (auto s : (*args))
            {
                argSize += s->GetType().size;
            }
            inst->_stream << "\taddi $sp, $sp, -" << argSize << " #args" << std::endl;
            int sizeCt = 0;
            for(int i = 0; i < (*args).size();i++)
            {
                if((*args)[i]->GetType().isRecord || (*args)[i]->GetType().isArray) //memberwise clone if array
                {
                    auto e = (*args)[i];
                    auto helper = std::make_shared<FC::Expr>(FC::Register::Allocate(),IntType());
                    for(int j = 0; j < e->GetType().size;j+=4)
                    {
                        inst->_stream << "\tlw " << helper->GetRegister()->name << ", "<< j <<  "(" << e->GetRegister()->name << ") #memberwise clone" << std::endl;
                        inst->_stream << "\tsw " << helper->GetRegister()->name << ", " << sizeCt << "($sp)" << std::endl;
                        sizeCt += 4;
                    }
                }
                else
                {
                    inst->_stream << "\tsw " << (*args)[i]->GetRegister()->name << ", " << sizeCt << "($sp)" <<
                    std::endl;
                    sizeCt += (*args)[i]->GetType().size;
                }
            }
        }
        inst->_stream << "\tmove $fp, $sp" << std::endl;
        inst->_stream << "\tjal " << name << " #function call" << std::endl;

        //get return value
        std::shared_ptr<Expr> expr;
        if(func->second->returnType != nullptr && func->second->returnType->name != "_void")
        {
            LVal r;
            r.name = "_return2";
            r.LValType = Frame;
            r.FramePointerOffset = -1 * func->second->returnType->size;
            r.Type = (*func->second->returnType);
            expr = LValToExpr(std::make_shared<LVal>(r));
        }
        //restore registers
        inst->_stream << "\tlw $fp, 0($sp) # restoring frame pointer" << std::endl;
        inst->_stream << "\tlw $ra, 4($sp) # restoring return address" << std::endl;
        for(int i = 0; i < toSpill.size();i++)
        {
            inst->_stream << "\tlw " << toSpill[i] << ", " << (i*4 + 8) << "($sp)" << std::endl;
        }
        inst->_stream << "\taddi $sp, $sp, " << (toSpill.size()*4 + 8) << " #restored registers" << std::endl;

        if(func->second->returnType == nullptr)
        {
            return nullptr;
        }
        if(func->second->returnType->name == "_void")
        {
            return nullptr;
        }
        return expr;
    }

    void AddLocalParams(std::shared_ptr<std::vector<std::pair<std::string, Type>>> params, Type returnType)
    {
        auto inst = Code::Inst();
        //inst->_stream << "#adding params to local symbol table" << std::endl;
        if(returnType.name != "_void")
        {
            LVal rl;
            rl.name = "_return";
            rl.LValType = Frame;
            rl.Type = returnType;
            rl.FramePointerOffset = returnType.size * -1;
            inst->LocalLValues["_return"] = std::make_shared<LVal>(rl);
        }
        if(params == nullptr) return;
        auto sizeCt = 0;
        for(int i = 0; i < (*params).size();i++)
        {
            LVal lv;
            lv.name = (*params)[i].first;
            lv.LValType = Frame;
            lv.Type = (*params)[i].second;
            lv.FramePointerOffset = sizeCt;
            sizeCt += (*params)[i].second.size;
            inst->LocalLValues[(*params)[i].first] = std::make_shared<LVal>(lv);
        }
    }

    void AddFunction(std::shared_ptr<Func> f)
    {
        auto inst = Code::Inst();
        auto res = inst->Functions.find(f->name);
        if(res != inst->Functions.end())
        {
            if (res->second->isForwardDeclared && !f->isForwardDeclared) // == forward decl implementation
            {

                if((res->second->params == nullptr && f->params != nullptr) ||
                        (res->second->params != nullptr && f->params == nullptr))
                {
                    std::cout << "Forwarded declaration params do not match implementation params for: " << f->name << std::endl;
                    exit(0);
                }

                if(res->second->params != nullptr && f->params != nullptr)
                {
                    if ((*res->second->params).size() != (*f->params).size())
                    {
                        std::cout << "Forwarded declaration params do not match implementation params for: " <<
                        f->name << std::endl;
                        exit(0);
                    }

                    for (int i = 0; i < (*res->second->params).size(); i++)
                    {
                        auto forw = (*res->second->params)[i];
                        auto impl = (*f->params)[i];
                        if (forw.first != impl.first || forw.second.name != impl.second.name ||
                            forw.second.size != impl.second.size)
                        {
                            std::cout << "Forwarded declaration params do not match implementation params for: " <<
                            f->name << std::endl;
                            exit(0);
                        }
                    }
                }
                inst->Functions.erase(f->name);
                inst->Functions.emplace(f->name, f);
                if(!f->isForwardDeclared)
                {
                    inst->_outFile << f->name << ": #proc/func" << std::endl;

                    inst->WriteToFileNow(); //write func body
                    inst->_outFile << "\tjr $ra #jump out of function" << std::endl;
                    inst->LocalLValues.clear(); //drop local symbol table
                }
            }
            else
            {
                std::cout << "Proc/Func " << f->name << " error: multiple declaration/definition" << std::endl;
                exit(0);
            }
        }
        else
        {
            inst->Functions.emplace(f->name, f);
            if(!f->isForwardDeclared)
            {
                inst->_outFile << f->name << ": #proc/func" << std::endl;

                inst->WriteToFileNow(); //write func body
                inst->_outFile << "\tjr $ra #jump out of function" << std::endl;
            }
            inst->LocalLValues.clear(); //drop local symbol table
        }
    }

    void CheckForwardDecls()
    {
        auto inst = Code::Inst();
        for(auto e : inst->Functions)
        {
            if(e.second->isForwardDeclared)
            {
                std::cout << "Proc/Func " << e.first << " has been forward declared but not defined" << std::endl;
                exit(0);
            }
        }
    }

    void AddReturn(std::shared_ptr<Expr> e)
    {
        auto inst = Code::Inst();
        if(inst->InMain)
        {
            std::cout << "Return statement cannot be in the main body" << std::endl;
            exit(0);
        }
        if(e == nullptr)    //Procedure
        {
            if(inst->LocalLValues.find("_return") == inst->LocalLValues.end())
            {
                inst->_stream << "\tjr $ra #jump out of function" << std::endl;
                return;
            }
            else
            {
                std::cout << "Return statement expression doesn't match proc/func declared return type:" << std::endl;
                exit(0);
            }

        }
        if(e->GetType().name != inst->LocalLValues["_return"]->Type.name)
        {
            std::cout << "Return statement expression doesn't match proc/func declared return type:" << std::endl;
            std::cout << "declared: " << inst->LocalLValues["_return"]->Type.name << " attempted to return: " << e->GetType().name << std::endl;
            exit(0);
        }
        if(e != nullptr)
        {
            Assignment(GetLValForIdent("_return"),e);   //assign expression to return value
        }
        inst->_stream << "\tjr $ra #jump out of function" << std::endl;
    }

    //////////////////////////////////
    //    Cusom Types
    //////////////////////////////////
    std::pair<std::vector<std::string>, Type> GetRecordFields(Type type)
    {
        auto inst = Code::Inst();
        std::pair<std::vector<std::string>, Type> a;
        a.second = type;
        if(inst->InMain)
        {
            a.first = inst->TempIdentList;
            inst->TempIdentList.clear();

        }
        else // temp ident list in function
        {
            a.first = inst->LocalTempIdentList;
            inst->LocalTempIdentList.clear();
        }

        return a;
    }

    Type GetRecordType(std::shared_ptr<std::vector<std::pair<std::vector<std::string>,FC::Type>>> fields)
    {
        return RecordType(*fields);
    }

    void DeclareType(std::string name, Type type)
    {
        boost::algorithm::to_lower(name);   //just in case
        auto inst = Code::Inst();
        if(inst->Types.find(name) != inst->Types.end())
        {
            std::cout << "Warning: redefining type " << name << " (this is legal behavior)" << std::endl;
            inst->Types.erase(name);
        }
        type.name = name;

        inst->Types.emplace(name,type);
    }

    Type GetArrayType(std::shared_ptr<Expr> lower, std::shared_ptr<Expr> higher, Type type)
    {
        if(lower->GetType().name != "integer" || higher->GetType().name != "integer"
           || lower->GetVal() == INT32_MIN ||higher->GetVal() == INT32_MIN)
        {
            std::cout << "Error: Array bounds must be compile time known integers" << std::endl;
            exit(1);
        }
        return ArrayType(type,lower->GetVal(),higher->GetVal());
    }

    std::shared_ptr<LVal> GetRecordField(std::shared_ptr<LVal> lval, std::string fieldName)
    {
        auto inst = Code::Inst();
        if(!lval->Type.isRecord)
        {
            std::cout << "Cannot use the the dot operator on a non-record type (Lval name: " << lval->name << " )" << std::endl;
            exit(0);
        }

        //This is a terrible way to cast, but I am not that good with polymorphism in C++ :-/
        Type& typeRef = lval->Type;
        auto res = (static_cast<RecordType&>(typeRef));
        auto offset  = res.GetFieldOffset(fieldName);
        LVal toRet;
        toRet.name = lval->name + "." + fieldName;  //TODO maybe something with this?
        toRet.Type = res.GetFieldType(fieldName);
        if(lval->LValType == Frame)
        {
            toRet.LValType = Frame;
            toRet.FramePointerOffset = lval->FramePointerOffset + offset;
        }
        else if (lval->LValType == Stack)
        {
            toRet.LValType = Stack;
            toRet.StackPointerOffset = lval->StackPointerOffset + offset;
        }
        else if(lval->LValType == Global)
        {
            toRet.LValType = Global;
            toRet.GlobalPointerOffset = lval->GlobalPointerOffset + offset;
        }

        return std::make_shared<LVal>(toRet);
    }

    std::shared_ptr<LVal> GetArrayMember(std::shared_ptr<LVal> lval, std::shared_ptr<Expr> index)
    {
        auto inst = Code::Inst();
        if(!lval->Type.isArray)
        {
            std::cout << "Cannot use the the bracket operator on a non-record type (Lval name: " << lval->name << " )" << std::endl;
            exit(0);
        }
        LVal toRet;
        toRet.name = lval->name;
        toRet.Type = *lval->Type.arrType;
        toRet.isArrayMember = true;
        toRet.LValType = lval->LValType;
        toRet.arrExpr = index;
        toRet.arrLowStart = lval->Type.arrLowerStart;
        toRet.FramePointerOffset = lval->FramePointerOffset;
        toRet.GlobalPointerOffset = lval->GlobalPointerOffset;
        toRet.StackPointerOffset = lval->StackPointerOffset;
        return std::make_shared<LVal>(toRet);
    }


}