#ifndef CODE_GEN
#define CODE_GEN

#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include <Expr/Expr.hpp>
#include <LVal.hpp>
#include <unordered_map>

namespace FC
{
    void AddMain();
    void AddConst(std::string id, int v);
    int AddIntExpr(int val);
    int AddString(std::string val);
    int LoadLVal(std::string id);

    class Code
    {
        public:
        
        static std::shared_ptr<Code> Inst();
        static std::string ArgFileOutName;
        Code(std::string fileName="out.asm")
        {
            std::cout << "Outputting code to: " << fileName << std::endl;
            _outFile.open(fileName);
        }
        
        ~Code()
        {
            _outFile.close();
        }
        
        std::ofstream _outFile;

        std::vector<Expr> Expressions;
        std::unordered_map<std::string, std::string> StringData;
        std::unordered_map<std::string,FC::LVal> LValues;
        std::string GetNextStringDataLabel()
        {
            _stringDataCt++;
            return "stringVal" + _stringDataCt;
        }
        private:
        static std::shared_ptr<Code> _code; 
        int _stringDataCt = -1;
    };

    
}

#endif