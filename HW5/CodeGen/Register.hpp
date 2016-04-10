/*
 * Fabio Gottlicher's CPSL Compiler
 * A01647928
 * Created for USU CS5300 - Compiler Construction, Spring 2016
 */

#ifndef REGISTRY_POOL
#define REGISTRY_POOL

#include <stdexcept>
#include <vector>
#include <string>
#include <memory>

namespace FC
{
    class Register
    {
        static std::vector<std::string> reg_pool;
        static std::vector<std::string> all_registers;

    public:

        static std::shared_ptr<Register> AllocateCustom(std::string);
        static std::shared_ptr<Register> Allocate();
        static std::vector<std::string> getUsed();

        ~Register()
        {
            Register::reg_pool.push_back(name);
        }

        //protected:
        Register(std::string n) : name(n)
        { };
        std::string name;

    };
}

#endif