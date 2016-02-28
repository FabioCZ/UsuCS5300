//
// Created by fabio on 2/27/16.
//
#include "Expr.hpp"
#include "../CodeGenerator.hpp"
namespace FC
{


    std::shared_ptr<FC::Register> Expr::GetRegister()
    {
        if (_exprType == Reg)
        {
            return _reg;
        }
        if (_exprType == Str)
        {
            std::cout << "Internal compiler error, li string" << std::cout;
            exit(1);
        }
        std::shared_ptr<Code> inst = Code::Inst();
        _reg = Register::Allocate();
        _exprType = Reg;
        this->_val = INT32_MIN;
        inst->_outFile << "\tli " << _reg->name << ", " << _val;
        return _reg;
    }
}
