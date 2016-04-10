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
            _code->_stream << ".global main" << std::endl << "j main_impl" << std::endl;

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
        inst->WriteToFileNow();
        inst->_outFile << "main_impl:" << std::endl;
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
        lv.name = id;
        if(e->GetType().name == "string")
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
            inst->_stream << "\tsw " << reg_name << ", " << lv.GlobalPointerOffset << "($gp) #Storing " << lv.name << std::endl;
        }
        inst->LValues[id] = std::make_shared<LVal>(lv);


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
            inst->_stream << "\tlw " << e.GetRegister()->name << ", " << lval->StackPointerOffset << "($sp)" << std::endl;
            return std::make_shared<Expr>(e);
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
            if(inst->LValues.find(a) != inst->LValues.end())
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

        std::string mem = lv->LValType == Stack ?
                          (std::to_string(lv->StackPointerOffset) + "($sp)") : (std::to_string(lv->GlobalPointerOffset) + "($gp)");

        std::string reg_name = e->GetRegister()->name;
        inst->_stream << "\tsw " << reg_name << ", " << mem << " #Storing " << lv->name << std::endl;

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
        auto res = Register::Allocate();
        inst->_stream << "\tadd " << res->name << ", " << l->GetRegister()->name << ", " << r->GetRegister()->name << std::endl;
//        if(l->GetType().name != r->GetType().name)
//        {
//            std::cout << "Syntax Error: Expressions don't agree in type, l:" << l->GetType().name << ", r: " <<  r->GetType().name << std::endl;
//
//            exit(0);
//        }
        return std::make_shared<Expr>(res, l->GetType());
    }

    const std::shared_ptr<Expr> ProcMinusExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        auto res = Register::Allocate();
        inst->_stream << "\tsub " << res->name << ", " << l->GetRegister()->name << ", " << r->GetRegister()->name << std::endl;
//        if(l->GetType().name != r->GetType().name)
//        {
//            std::cout << "Syntax Error: Expressions don't agree in type, l:" << l->GetType().name << ", r: " <<  r->GetType().name << std::endl;
//
//            exit(0);
//        }
        return std::make_shared<Expr>(res, l->GetType());
    }

    const std::shared_ptr<Expr> ProcDivideExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        auto res = Register::Allocate();
        inst->_stream << "\tdiv " << res->name << ", " << l->GetRegister()->name << ", " << r->GetRegister()->name << std::endl;
//        if(l->GetType().name != r->GetType().name)
//        {
//            std::cout << "Syntax Error: Expressions don't agree in type, l:" << l->GetType().name << ", r: " <<  r->GetType().name << std::endl;
//
//            exit(0);
//        }
        return std::make_shared<Expr>(res, l->GetType());
    }

    const std::shared_ptr<Expr> ProcMultiplyExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        auto res = Register::Allocate();
        inst->_stream << "\tmul " << res->name << ", " << l->GetRegister()->name << ", " << r->GetRegister()->name << std::endl;
//        if(l->GetType().name != r->GetType().name)
//        {
//            std::cout << "Syntax Error: Expressions don't agree in type, l:" << l->GetType().name << ", r: " <<  r->GetType().name << std::endl;
//
//            exit(0);
//        }
        return std::make_shared<Expr>(res, l->GetType());
    }

    const std::shared_ptr<Expr> ProcModExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
    {
        auto inst = Code::Inst();
        auto res = Register::Allocate();
        inst->_stream << "\trem " << res->name << ", " << l->GetRegister()->name << ", " << r->GetRegister()->name << std::endl;
//        if(l->GetType().name != r->GetType().name)
//        {
//            std::cout << "Syntax Error: Expressions don't agree in type, l:" << l->GetType().name << ", r: " <<  r->GetType().name << std::endl;
//
//            exit(0);
//        }
        return std::make_shared<Expr>(res, l->GetType());
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
        inst->_stream << "\tsub " << r->GetRegister()->name << ", $zero, " << r->GetRegister()->name << std::endl;
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
        inst->_outFile << "WhileBegin" << inst->addLabelNumber() << ":" << std::endl;
    }

    void WhileHead(std::shared_ptr<Expr> e)
    {
        auto inst = Code::Inst();
        inst->WriteToFileNow();
        inst->_outFile << "\tbeq $zero," << e->GetRegister()->name << ", WhileEnd" << inst->getCurrLabelNumber() << std::endl;
    }


    void WhileEnd()
    {
        auto inst = Code::Inst();
        inst->WriteToFileNow();
        auto labelNum = inst->dropLabelNumber();
        inst->_outFile << "\tj WhileBegin" << labelNum << std::endl;
        inst->_outFile << "\tWhileEnd"<< labelNum << ":" << std::endl;
    }

    void RepeatHead()
    {
        auto inst = Code::Inst();
        inst->WriteToFileNow();
        inst->_outFile << "RepeatBegin" << inst->addLabelNumber() << ":" << std::endl;

    }

    void RepeatEnd(std::shared_ptr<Expr> e)
    {
        auto inst = Code::Inst();
        inst->WriteToFileNow();
        inst->_outFile << "\tbeq $zero," << e->GetRegister()->name << ", RepeatBegin" << inst->dropLabelNumber() << std::endl;
    }

    void IfHead(std::shared_ptr<Expr> e)
    {
        auto inst = Code::Inst();
        inst->WriteToFileNow();
        inst->_outFile << "\t beq $zero, " << e->GetRegister()->name << ", ElseLabel" << inst->incrElseCount() << "_" << inst->addLabelNumber() << " #if/else jump" << std::endl;
    }

    void ElseIfSuperHead()
    {
        auto inst = Code::Inst();
        auto elseLabel = inst->getElseCount();
        inst->WriteToFileNow();
        inst->_outFile << "j ElseLabelEnd" << "_" << inst->getCurrLabelNumber() << " #jump to after else" << std::endl;
        inst->_outFile << "ElseLabel" << elseLabel << "_" << inst->getCurrLabelNumber() << ": #else label" << std::endl;
    }


    void ElseIfHead(std::shared_ptr<Expr> e)
    {
        auto inst = Code::Inst();
        inst->WriteToFileNow();
        inst->_outFile << "\t beq $zero, " << e->GetRegister()->name << ", ElseLabel" << inst->incrElseCount() << "_" << inst->getCurrLabelNumber() << " #if/else jump" << std::endl;
    }

    void ElseHead()
    {
        auto inst = Code::Inst();
        auto elseLabel = inst->getElseCount();
        inst->WriteToFileNow();
        inst->_outFile << "j ElseLabelEnd" << "_" << inst->getCurrLabelNumber() << " #jump to after else" << std::endl;
        inst->_outFile << "ElseLabel" << elseLabel << "_" << inst->getCurrLabelNumber() << ": #else label" << std::endl;
    }

    void IfEnd()
    {
        auto inst = Code::Inst();
        inst->WriteToFileNow();
        inst->_outFile << "ElseLabelEnd" << "_" << inst->dropLabelNumber() << ":" << std::endl;
    }

    void ForHead(std::string s, std::shared_ptr<Expr> e)
    {
        //std::cout << "ForHead" << std::endl;
        auto inst = Code::Inst();
        AddIdent(s);
        AddVariables(IntType());
        Assignment(GetLValForIdent(s),e);
        inst->WriteToFileNow();
        auto f = std::make_shared<ForInfo>(s,true);
        inst->ForInfos.emplace_back(f);
    }

    void ToHead(bool isUp, std::shared_ptr<Expr> e)
    {
        //std::cout << "Tohead" << isUp << std::endl;
        auto inst = Code::Inst();
        inst->WriteToFileNow();
        inst->_outFile << "ForStart" << inst->addLabelNumber() << ":" << std::endl;
        auto fi = inst->ForInfos.back()->varName;
        inst->ForInfos.pop_back();
        inst->ForInfos.push_back(std::make_shared<ForInfo>(fi,isUp));
        auto name = inst->ForInfos.back()->varName;
        auto e2 = std::const_pointer_cast<Expr>(LValToExpr(GetLValForIdent(name)))->GetRegister();
        auto e1 = e->GetRegister();
        inst->WriteToFileNow();
        inst->_outFile << "\tbeq " << e1->name << ", " << e2->name << ", ForEnd" << inst->getCurrLabelNumber() << std::endl;

    }

    void ForEnd()
    {
        //std::cout << "forend" << std::endl;
        auto inst = Code::Inst();
        inst->WriteToFileNow();
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
        inst->WriteToFileNow();
        inst->_outFile << "\tj ForStart" << inst->getCurrLabelNumber() << std::endl;
        inst->_outFile << "ForEnd" << inst->dropLabelNumber() << ":" << std::endl;

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

        //spill registers
        std::cout << "calling func" << std::endl;
        inst->_stream << "\tjal " << name << " #function call" << std::endl;
        return nullptr;
        //restore registers

    }

    void AddFunction(std::shared_ptr<Func> f)
    {
        auto inst = Code::Inst();
        auto res = inst->Functions.find(f->name);
        if(res != inst->Functions.end())
        {
            if (res->second->isForwardDeclared && !f->isForwardDeclared) // == forward decl implementation
            {
                inst->Functions.erase(f->name);
                //TODO check params and return type
                inst->Functions.emplace(f->name, f);
            }
            else
            {
                std::cout << "Proc/Func " << f->name << " error: multiple declaration/definition" << std::endl;
            }
        }
        else
        {
            inst->Functions.emplace(f->name, f);
            if(!f->isForwardDeclared)
            {
                inst->_outFile << f->name << ": #proc/func" << std::endl;
            }
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


}