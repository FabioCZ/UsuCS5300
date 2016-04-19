/*
 * Fabio Gottlicher's CPSL Compiler
 * A01647928
 * Created for USU CS5300 - Compiler Construction, Spring 2016
 */

#ifndef CPSL_TYPE_HPP
#define CPSL_TYPE_HPP

#include <string>
#include <tuple>
#include <algorithm>
#include <memory>
#include <iostream>
namespace FC
{
    class Type
    {
    public:
        std::vector<std::tuple<std::string,Type,int>> fields;
        std::shared_ptr<Type> arrType;

        int size = -2;
        std::string name;
        bool isRecord;
        bool isArray;
        ~Type() = default;

    };

    class VoidType : public Type
    {
    public:
        VoidType()
        {
            this->size = 0;
            this->name = "_void";
            this->isRecord = false;
            this->isArray = false;
        }
    };

    class IntType : public Type
    {
    public:
        IntType()
        {
            this->size = 4;
            this->name = "integer";
            this->isRecord = false;
            this->isArray = false;
        }

    };

    class CharType : public Type
    {
    public:
        CharType()
        {
            this->size = 4;
            this->name = "char";
            this->isRecord = false;
            this->isArray = false;
        }
    };

    class BoolType : public Type
    {
    public:
        BoolType()
        {
            this->size = 4;
            this->name = "boolean";
            this->isRecord = false;
            this->isArray = false;
        }
    };

    class StringType : public Type
    {
    public:
        StringType()
        {
            this->size = -1;
            this->name = "string";
            this->isRecord = false;
            this->isArray = false;
        }
    };

    class RecordType : public Type
    {
    public:

        RecordType(std::vector<std::pair<std::vector<std::string>, FC::Type>> fields)
        {
            this->size = 0;
            this->name = "record_proto";
            this->isRecord = true;
            this->isArray = false;
            for(auto f : fields)
            {
                auto thisType = f.second;
                for(auto g : f.first)
                {
                    std::tuple<std::string,Type,int> t {g,thisType,this->size};
                    size += thisType.size;
                    this->fields.push_back(t);
                }
            }
        }

        int GetFieldOffset(std::string name)
        {
            auto res = std::find_if(this->fields.begin(),this->fields.end(), [name](std::tuple<std::string,Type,int> e){return std::get<0>(e) == name;});
            if(res != this->fields.end())
            {
                return std::get<2>(*res);
            }
            std::cout << "Error: " << name << " is not a field of the currently parsed record type" << std::endl;
            exit(1);
        }

        Type GetFieldType(std::string name)
        {
            auto res = std::find_if(this->fields.begin(),this->fields.end(), [name](std::tuple<std::string,Type,int> e){return std::get<0>(e) == name;});
            if(res != this->fields.end())
            {
                return std::get<1>(*res);
            }
            std::cout << "Error: " << name << " is not a field of the currently parsed record type" << std::endl;
            exit(1);
        }
    };

    class ArrayType : public Type
    {
    public:

        ArrayType(Type type, int low, int high)
        {
            this->isArray = true;
            this->isRecord = false;
            if(high < low)
            {
                std::cout<< "The high bound for an array cannot be smaller than its low bound" << std::endl;
                exit(1);
            }
            this->size = high - low +1;
            this->name = "array_proto";
            this->arrType = std::make_shared<Type>(type);

        }
    };
}
#endif //CPSL_TYPE_HPP
