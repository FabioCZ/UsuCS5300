//
// Created by fabio on 4/9/16.
//

#ifndef F_CPSL_FUNC_HPP
#define F_CPSL_FUNC_HPP

#include<Type.hpp>
#include <vector>
#include <string>
#include <utility>
#include <memory>

namespace FC
{
    class Func
    {
    public:
        Func(std::shared_ptr<Type> returnType,std::shared_ptr<std::vector<std::pair<std::string,Type>>> params, std::string name)
        {
            this->returnType = returnType;
            this->params = params;
            this->name = name;
        }

        std::shared_ptr<Type> returnType;
        std::shared_ptr<std::vector<std::pair<std::string,Type>>> params;
        std::string name;
        bool isForwardDeclared;

        int getArgsSize()
        {
            int size = 0;
            for(auto s : (*params))
            {
                size += s.second.size;
            }
            return size;
        }
    };
}


#endif //F_CPSL_FUNC_HPP
