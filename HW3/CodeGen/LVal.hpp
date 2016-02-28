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
        Stack = 1,
        Global = 2,
        Data = 3,
        Const = 4
    };

    struct LVal
    {
        FC::Type Type;
        FC::LValType LValType;
        int StackPointerOffset;
        int GlobalPointerOffset;
        std::string DataLabel;
        int ConstValue;
        std::string name;
    };

}
#endif //CPSL_LVAL_HPP
