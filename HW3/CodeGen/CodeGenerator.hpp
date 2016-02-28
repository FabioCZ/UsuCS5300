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
    void AddConst(std::string id, std::shared_ptr<Expr> e);
    const std::shared_ptr<Expr> AddIntExpr(int val);
    const std::shared_ptr<Expr> AddString(std::string val);
    const std::shared_ptr<Expr> LoadLVal(std::shared_ptr<LVal> lv);
    void AddIdent(std::string id);
    void AddVariables(Type type);
    Type SimpleTypeLookup(std::string typeName);
    void WriteConstData();
    void Assignment(std::shared_ptr<LVal> lv, std::shared_ptr<Expr> e);
    std::shared_ptr<LVal> GetLValForIdent(std::string s);


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

        std::vector<std::shared_ptr<Expr>> Expressions;
        std::unordered_map<std::string, std::shared_ptr<Expr>> ConstData;
        std::unordered_map<std::string,std::shared_ptr<FC::LVal> > LValues;
        std::vector<std::string> TempIdentList;
        std::string GetNextStringDataLabel()
        {
            _stringDataCt++;
            return "stringVal" + _stringDataCt;
        }
        int AllocateStackPointer(int size);
        int AllocateGlobalPointer(int size);

        private:
        static std::shared_ptr<Code> _code; 
        int _stringDataCt = -1;

        int _currGPOffset = 0;
        int _currSPOffset = 0;
    };

    
}

#endif