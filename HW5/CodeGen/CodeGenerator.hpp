/*
 * Fabio Gottlicher's CPSL Compiler
 * A01647928
 * Created for USU CS5300 - Compiler Construction, Spring 2016
 */

#ifndef CODE_GEN
#define CODE_GEN

#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include <Expr/Expr.hpp>
#include <LVal.hpp>
#include <unordered_map>
#include <sstream>
#include <map>
#include "Func.hpp"

namespace FC
{
    struct ForInfo
    {
        ForInfo(std::string s, bool i) : varName(s), isUp(i){}
        std::string varName;
        bool isUp;
    };
    void AddMain();
    void MainBlock();
    void AddConst(std::string id, std::shared_ptr<Expr> e);

    void AddIdent(std::string id);
    void AddVariables(Type type);
    Type SimpleTypeLookup(std::string typeName);
    void WriteConstData();
    std::shared_ptr<LVal> GetLValForIdent(std::string s);

    //StatementList
    void WriteStatement();

    //Statements
    void Assignment(std::shared_ptr<LVal> lv, std::shared_ptr<Expr> e);
    void WriteExpr(std::shared_ptr<Expr> e);
    void ReadToLVal(std::shared_ptr<LVal> lv);
    void Stop();

    //Control structures/Statements
    void AddIfStatement();
    void WhileSuperHead();
    void WhileHead(std::shared_ptr<Expr> e);
    void WhileEnd();
    void RepeatHead();
    void RepeatEnd(std::shared_ptr<Expr> e);
    void IfHead(std::shared_ptr<Expr> e);
    void ElseIfSuperHead();
    void ElseIfHead(std::shared_ptr<Expr> e);
    void ElseHead();
    void IfEnd();

    void ForHead(std::string s, std::shared_ptr<Expr> e);
    void ToHead(bool isUp,std::shared_ptr<Expr> e);
    void ForEnd();

    //Expressions
    const std::shared_ptr<Expr> ProcBinaryExpr(std::string opName, std::shared_ptr<Expr> l, std::shared_ptr<Expr> r);
    const std::shared_ptr<Expr> ProcOrExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r);
    const std::shared_ptr<Expr> ProcAndExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r);
    const std::shared_ptr<Expr> ProcEqualExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r);
    const std::shared_ptr<Expr> ProcNotEqualExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r);
    const std::shared_ptr<Expr> ProcLessEqualExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r);
    const std::shared_ptr<Expr> ProcGreaterEqualExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r);
    const std::shared_ptr<Expr> ProcLessThanExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r);
    const std::shared_ptr<Expr> ProcGreaterThanExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r);

    const std::shared_ptr<Expr> ProcPlusExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r);
    const std::shared_ptr<Expr> ProcMinusExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r);
    const std::shared_ptr<Expr> ProcDivideExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r);
    const std::shared_ptr<Expr> ProcMultiplyExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r);
    const std::shared_ptr<Expr> ProcModExpr(std::shared_ptr<Expr> l, std::shared_ptr<Expr> r);
    const std::shared_ptr<Expr> ProcNotExpr(std::shared_ptr<Expr> r);
    const std::shared_ptr<Expr> ProcUnaryMinusExpr(std::shared_ptr<Expr> r);

    const std::shared_ptr<Expr> ProcDecrement(std::shared_ptr<Expr> e);
    const std::shared_ptr<Expr> ProcIncrement(std::shared_ptr<Expr> e);

    const std::shared_ptr<Expr> ProcIntExpr(int val);
    const std::shared_ptr<Expr> ProcStringExpr(std::string val);
    const std::shared_ptr<Expr> ProcCharExpr(char val);
    const std::shared_ptr<Expr> LValToExpr(std::shared_ptr<LVal> lv);
    const std::shared_ptr<Expr> ToChar(std::shared_ptr<Expr> e);
    const std::shared_ptr<Expr> ToInt(std::shared_ptr<Expr> e);

    //Function stuff
    void AddLocalParams(std::shared_ptr<std::vector<std::pair<std::string,Type>>> params, Type returnType);
    void AddFunction(std::shared_ptr<Func> f);
    void CheckForwardDecls();
    const std::shared_ptr<Expr> CallFunction(std::string name, std::shared_ptr<std::vector<std::shared_ptr<Expr>>> args);
    void AddReturn(std::shared_ptr<Expr> e);

    class Code
    {
        public:
        
        static std::shared_ptr<Code> Inst();
        static std::string ArgFileOutName;
        Code()
        {
            std::cout << "Outputting code to: " << ArgFileOutName << std::endl;
            _outFile.open(ArgFileOutName);
        }
        
        ~Code()
        {
            _outFile.close();
        }
        
        std::ofstream _outFile;
        std::stringstream _stream;
        void WriteToFileNow();

        int addLabelNumber();
        int getCurrLabelNumber();
        int  dropLabelNumber();

        int incrElseCount();
        int getElseCount();


        std::vector<std::shared_ptr<ForInfo>> ForInfos;
        std::vector<std::shared_ptr<Expr>> Expressions;
        std::unordered_map<std::string, std::shared_ptr<Expr>> ConstData;
        std::unordered_map<std::string,std::shared_ptr<FC::LVal> > LValues;
        std::unordered_map<std::string,std::shared_ptr<FC::LVal> > LocalLValues;

        std::unordered_map<std::string, std::shared_ptr<Func> > Functions;
        std::vector<std::string> TempIdentList;
        std::vector<std::string> LocalTempIdentList;

        bool InMain;
        std::string GetNextStringDataLabel()
        {
            _stringDataCt++;
            return "stringVal" + std::to_string(_stringDataCt);
        }
        int AllocateStackPointer(int size);
        int AllocateGlobalPointer(int size);

        private:
        std::vector<int> _labelNumbers;
        int _labelCounter = 0;
        std::map<int,int> _elseLabels;


        static std::shared_ptr<Code> _code;
        int _stringDataCt = -1;

        int _currGPOffset = 0;
        int _currSPOffset = 0;
    };

    
}

#endif