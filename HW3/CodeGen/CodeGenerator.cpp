#include <CodeGenerator.hpp>
#include <unordered_map>
#include "LVal.hpp"
#include "Register.hpp"
#include "Expr/Expr.hpp"

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
        inst->_outFile << "Test code";
    }


    void AddConst(std::string id, int v)
    {
        std::cout << "CONST";
        auto inst = Code::Inst();

    }

    int AddIntExpr(int val)
    {
        auto inst = Code::Inst();
        Expr e(val, IntType());
        int index = inst->Expressions.size();
        inst->Expressions.push_back(e);
        std::cout << "ADDED INT" << std::endl;
        return index;
    }

    int AddString(std::string val)
    {
        auto inst = Code::Inst();
        auto label = inst->GetNextStringDataLabel();
        inst->StringData[label] = val;
        Expr e(val);

        int index = inst->Expressions.size();
        inst->Expressions.push_back(e);
        return index;
    }

    int LoadLVal(std::string id)
    {
        auto inst = Code::Inst();
        auto lvalRes = inst->LValues.find(id);
        if(lvalRes == inst->LValues.end())
        {
            std::cout << "Can't find lval " << id << std::endl;
            return -1;
        }
        auto lval = lvalRes->second;

        int index;
        if(lval.LValType == Const)
        {
            FC::Expr e(lval.ConstValue, lval.Type);
            index = inst->Expressions.size();
            inst->Expressions.push_back(e);
        }
        else if(lval.LValType == Stack)
        {
            FC::Expr e(FC::Register::Allocate(), lval.Type);
            inst->_outFile << "\tlw " << e.GetRegister()->name << ", " << lval.StackPointerOffset << "($sp)" << std::endl;
            index = inst->Expressions.size();
            inst->Expressions.push_back(e);
        }
        else if(lval.LValType == Global)
        {
            FC::Expr e(FC::Register::Allocate(), lval.Type);
            inst->_outFile << "\tlw " << e.GetRegister()->name << ", " << lval.GlobalPointerOffset << "($gp)" << std::endl;
            index = inst->Expressions.size();
            inst->Expressions.push_back(e);

        }
        else // data
        {
            FC::Expr e(FC::Register::Allocate(), lval.Type);
            inst->_outFile << "\tla " << e.GetRegister()->name << ", " << lval.DataLabel << std::endl;
            index = inst->Expressions.size();
            inst->Expressions.push_back(e);
        }
        return index;
    }
}