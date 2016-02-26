#ifndef CODE_GEN
#define CODE_GEN

#include <memory.h>

namespace CodeGen
{
    void addMain();
    
    class Code
    {
        public:
        
        static std::shared_ptr<Code> instance()
        {
            if(_code == nullptr)
            {
                _code = std::make_shared<Code>();
            }
            return _code;
        }
        private:
        Code _code;
    }
    
}

#endif