//
// Created by fabio on 2/27/16.
//

#ifndef CPSL_LVAL_HPP
#define CPSL_LVAL_HPP
#include <string>
#include "Type.hpp"

namespace FC
{
    enum LValType
    {
        Stack,
        Global,
        Data,
        Const
    };

    struct LVal
    {
        FC::Type Type;
        FC::LValType LValType;
        int StackPointerOffset;
        int GlobalPointerOffset;
        std::string DataLabel;
        int ConstValue;
    };

}
#endif //CPSL_LVAL_HPP
