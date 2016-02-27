//
// Created by fabio on 2/27/16.
//

#ifndef CPSL_TYPE_HPP
#define CPSL_TYPE_HPP
namespace FC
{
    class Type
    {
    public:
        int size;
        std::string name;
        ~Type() = default;

    };

    class IntType : public Type
    {
    public:
        const int size = 4;
        const std::string name = "int";
    };

    class CharType : public Type
    {
    public:
        const int size = 4;
        const std::string name = "char";
    };

    class BoolType : public Type
    {
    public:
        const int size = 4;
        const std::string name = "bool";
    };

    class StringType : public Type
    {
    public:
        const int size = -1;
        const std::string name = "string";
    };
}
#endif //CPSL_TYPE_HPP
