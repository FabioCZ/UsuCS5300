/*
 * Fabio Gottlicher's CPSL Compiler
 * A01647928
 * Created for USU CS5300 - Compiler Construction, Spring 2016
 */

#ifndef CPSL_TYPE_HPP
#define CPSL_TYPE_HPP
namespace FC
{
    class Type
    {
    public:
        int size = -2;
        std::string name;
        ~Type() = default;

    };

    class VoidType : public Type
    {
    public:
        VoidType()
        {
            this->size = 0;
            this->name = "void";
        }
    };

    class IntType : public Type
    {
    public:
        IntType()
        {
            this->size = 4;
            this->name = "integer";
        }

    };

    class CharType : public Type
    {
    public:
        CharType()
        {
            this->size = 4;
            this->name = "char";
        }
    };

    class BoolType : public Type
    {
    public:
        BoolType()
        {
            this->size = 4;
            this->name = "boolean";
        }
    };

    class StringType : public Type
    {
    public:
        StringType()
        {
            this->size = -1;
            this->name = "string";
        }
    };
}
#endif //CPSL_TYPE_HPP
