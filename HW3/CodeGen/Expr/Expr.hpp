//
// Created by fabio on 2/27/16.
//

#ifndef CPSL_EXPR_HPP
#define CPSL_EXPR_HPP

#include "../Register.hpp"
#include <memory>
#include <CodeGen/Type.hpp>

namespace FC
{
    enum ExprType
    {
        Reg,
        Int,
        Str
    };
    class Expr {
    public:

        std::string GetStringVal() {return _stringVal;}
        int GetVal() {return _val;}
        std::shared_ptr<FC::Register> GetRegister() {return _reg;}
        ExprType GetExprType() { return _exprType;}
        Type GetType() {return _type;}

        Expr(std::shared_ptr<FC::Register> reg, Type type)
        {
            this->_reg = reg;
            this->_exprType = Reg;
            this->_val = INT32_MIN;
            this->_type = type;
        }

        Expr(int val, Type type)
        {
            this->_val = val;
            this->_exprType = Int;
            this->_type = type;
        };

        Expr(std::string val)
        {
            this->_stringVal = val;
            this->_exprType = Str;
            this->_type = StringType();
        }
    private:
        int _val = -1;
        std::string _stringVal = "ERROR! THIS VALUE IS NOT SET!";
        std::shared_ptr<FC::Register> _reg = nullptr;
        ExprType _exprType;
        Type _type;
    };
}


#endif //CPSL_EXPR_HPP
