/*
 * Fabio Gottlicher's CPSL Compiler
 * A01647928
 * Created for USU CS5300 - Compiler Construction, Spring 2016
 */


#ifndef CPSL_LVAL_HPP
#define CPSL_LVAL_HPP
#include <string>
#include <CodeGen/Expr/Expr.hpp>
#include "Type.hpp"


namespace FC
{
    enum LValType
    {
        Stack = 1,
        Global = 2,
        Data = 3,
        Const = 4,
        Frame = 5
    };

    struct LVal
    {
        FC::Type Type;
        FC::LValType LValType;
        int StackPointerOffset;
        int GlobalPointerOffset;
        int FramePointerOffset;
        std::string DataLabel;
        int ConstValue;
        std::string name;
        std::shared_ptr<Expr> arrExpr;
        bool isArray = false;
    };

}
#endif //CPSL_LVAL_HPP
