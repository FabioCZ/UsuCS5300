/*
 * Fabio Gottlicher's CPSL Compiler
 * A01647928
 * Created for USU CS5300 - Compiler Construction, Spring 2016
 */

#ifndef CPSL_EXPR_HPP
#define CPSL_EXPR_HPP

#include "../Register.hpp"
#include <memory>
#include "../Type.hpp"
#include <iostream>

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
        int GetVal() {
            if(this->_val == INT32_MIN)
            {
                std::cout << "The desired expression is not of integer type, and cannot be evaluated compile time" << std::endl;
                std::cout << "Hint: you're probably seeing this because of a array declaration bound error." << std::endl;
                exit(1);
            }
            return this->_val;
        }
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

        void CastCharToInt()
        {
            if(this->_type.name == "integer" || this->_type.name == "char")
            {
                this->_type = IntType();
            }
            else
            {
                std::cout << "Only chars can be cast to integers" << std::endl;
                exit(1);
            }
        }

        void CastIntToChar()
        {
            if(this->_type.name == "integer" || this->_type.name == "char")
            {
                this->_type = CharType();
            }
            else
            {
                std::cout << "Only integers can be cast to chars" << std::endl;
                exit(1);
            }
        }

        std::shared_ptr<FC::Register> GetRegister();
        std::shared_ptr<FC::Register> GetCustomRegister(std::string name);

    private:
        int _val = INT32_MIN;
        std::string _stringVal = "ERROR! THIS VALUE IS NOT SET!";
        std::shared_ptr<FC::Register> _reg = nullptr;
        ExprType _exprType;
        Type _type;
    };
}


#endif //CPSL_EXPR_HPP
