    /*  
        Keano Gottlicher, CS5300 Spring 2016
        HW1 - Lexical Analysis for CPSL
        See Readme.txt for compiler instructions.
    */
%{
#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <vector>

yyFlexLexer fl;

void printKeyword(std::string s)
{
    std::cout << "Found keyword : " << s << " at line : " << fl.lineno() << std::endl;
}

void printOperator(std::string s)
{
    std::cout << "Found operator : " << s << " at line : " << fl.lineno() << std::endl;    
}

void printIdentifier(std::string s)
{
    std::cout << "Found identifier: " << s << " at line : " << fl.lineno() << std::endl;
}

void printIntLiteral(std::string type, int value)
{
    std::cout << "Found integer literal in base: " << type.c_str() << " ,value (dec):   " << value << " at line : " << fl.lineno() << std::endl;
}

void printStringLiteral(std::string s)
{
    std::cout << "Found string literal: " << s << " at line: " << fl.lineno() << std::endl;
}

void printCharLiteral(char c)
{
    std::cout << "Found character literal: " << c << " at line: " << fl.lineno() << std::endl;
}

std::string replaceReserved(std::string s)
{
    boost::replace_all(s,"\\n","\n");
    boost::replace_all(s,"\\r","\r");
    boost::replace_all(s,"\\b","\b");
    boost::replace_all(s,"\\t","\t");
    boost::replace_all(s,"\\f","\f");
    boost::replace_all(s,"\\","");
    return s;
}

std::string cleanUpString(std::string s)
{
    boost::erase_all(s, "\"");
    s = replaceReserved(s);
    return s;
}

char cleanUpChar(std::string s)
{
    boost::erase_all(s, "'");
    s = replaceReserved(s);
    return s.c_str()[0];
}

void printComment(std::string s)
{
    boost::erase_all(s,"$");
    std::cout << "Found comment with content: " << s << " at line: " << fl.lineno() << std::endl;
}

void printError(std::string s)
{
    std::cout << "Found unknow character (error): " << s << " at line: " << fl.lineno() << std::endl;
}
%}
letter [a-zA-Z]
digit [0-9]
%option noyywrap
%option yylineno
%option c++
%%

     /* keywords */
array { printKeyword("array"); }
begin { printKeyword("begin"); }
chr { printKeyword("chr"); }
const { printKeyword("const"); }
do { printKeyword("do"); }
downto { printKeyword("downto"); }
else { printKeyword("else"); }
elseif { printKeyword("elseif"); }
end { printKeyword("end"); }
for { printKeyword("for"); }
forward { printKeyword("forward"); }
function { printKeyword("function"); }
if { printKeyword("if"); }
of { printKeyword("of"); }
ord { printKeyword("ord"); }
pred { printKeyword("pred"); }
procedure { printKeyword("procedure"); }
read { printKeyword("read"); }
record { printKeyword("record"); }
ref { printKeyword("ref"); }
repeat { printKeyword("repeat"); }
return { printKeyword("return"); }
stop { printKeyword("stop"); }
succ { printKeyword("succ"); }
then { printKeyword("then"); }
to { printKeyword("to"); }
type { printKeyword("type"); }
until { printKeyword("until"); }
var { printKeyword("var"); }
while { printKeyword("while"); }
write { printKeyword("write"); }

    /* operators */
\+ { printOperator("plus (+)");}
\- { printOperator("minus (-)");}
\* { printOperator("times (*)");}
\/ { printOperator("divide (/)");}
\& { printOperator("and (&)");}
\| { printOperator("or (|)");}
\~ { printOperator("not (~)");}
\= { printOperator("equals (=)");} 
\<> { printOperator("less than - greater than (<>)");}
\< { printOperator("less than (<)");}
\<= { printOperator("less or equal than (<=)");}
\> { printOperator("greater than (>)");}
\>= { printOperator("greater or equal than (>=)");}
\. { printOperator("dot (.)");}
\, { printOperator("comma (,)");}
\: { printOperator("colon (:)");}
\; { printOperator("semicolon (;)");}
\( { printOperator("open parenthesis (()");}
\) { printOperator("close parenthesis ())");}
\[ { printOperator("open bracket ([)");}
\] { printOperator("close bracket (])");}
\:= { printOperator("colon-equals (:=)");}
\% { printOperator("percent (%)");}

    /* Identifier */
{letter}({letter}|{digit}|_)* {printIdentifier(fl.YYText());}
    /* literals */
0x([0-9a-fA-F])+ {printIntLiteral("hexadecimal", (int)strtol(fl.YYText(),NULL,0));}  //Here the language specification is vague whether a-f should be caps or no caps, so I match both
0({digit})+ {printIntLiteral("octal", (int)strtol(fl.YYText(),NULL,8));}
[1-9]({digit})+ {printIntLiteral("decimal", (int)strtol(fl.YYText(),NULL,10));}
\"[\x20-\x7e]+\" {printStringLiteral(cleanUpString(fl.YYText()));}
'([\x21-\x5b\x5d-\x7e]|(\\[\x21-\x7e]))' {printCharLiteral(cleanUpChar(fl.YYText()));}
 
    /* Comments */
\$.*\n  {printComment(fl.YYText());}
    /* other */
[ \n\t\r]+ {/*whitespace, nothing to do here*/}
. { printError(fl.YYText());}

%%

int main(int argc, char *argv[])
{
    fl.yylex();
    return 0;
}