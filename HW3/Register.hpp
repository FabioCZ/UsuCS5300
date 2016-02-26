#ifndef REGISTRY_POOL
#define REGISTRY_POOL

namespace CodeGen
{
    
    class Register
    {
        public:
        
        static void init()
        {
            reg_pool = new std::vector<std::string> { "$t0", "$t1", "$t2", "$t3", "$t4", "$t5","$t6", "$t7", "$t8","$t9", 
            "$s0", "$s1", "$s2", "$s3","$s4", "$s5","$s6", "$s7" };
        }
        
        static std::unique_ptr<string>
        ~Register()
        {
            reg_pool.push_back(name);
        }
        private:
        Register(std::string n) : name(n);
        std::string name;
        static std::vector<std::string> reg_pool;
    }
}

#endif