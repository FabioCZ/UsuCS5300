/*
 * Fabio Gottlicher's CPSL Compiler
 * A01647928
 * Created for USU CS5300 - Compiler Construction, Spring 2016
 */

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
        inst->_outFile << "\tli " << _reg->name << ", " << _val << std::endl;
        this->_val = INT32_MIN; //reset value, as we shouldn't need it
        return _reg;
    }
}
