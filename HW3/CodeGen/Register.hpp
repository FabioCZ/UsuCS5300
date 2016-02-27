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
    public:

        static std::shared_ptr<Register> Allocate();

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