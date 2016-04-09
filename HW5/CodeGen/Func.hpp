//
// Created by fabio on 4/9/16.
//

#ifndef F_CPSL_FUNC_HPP
#define F_CPSL_FUNC_HPP

#include<Type.hpp>
#include <vector>
#include <string>
#include <utility>

namespace FC
{
    class Func
    {
    public:
        Func(Type returnType,std::vector<std::pair<std::string,Type>> params, std::string name)
        {
            this->returnType = returnType;
            this->params = params;
            this->name = name;
        }
        Type returnType;
        std::vector<std::pair<std::string,Type>> params;
        std::string name;
    };
}


#endif //F_CPSL_FUNC_HPP
