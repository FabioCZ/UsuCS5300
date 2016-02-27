//
// Created by fabio on 2/27/16.
//

#ifndef CPSL_INTEXPR_HPP
#define CPSL_INTEXPR_HPP

#include "Expr.hpp"

namespace  FC
{
    class IntExpr : public Expr
    {

    public:
        IntExpr(int val) : Expr(val, IntType())
        { }
    };
}

#endif //CPSL_INTEXPR_HPP
