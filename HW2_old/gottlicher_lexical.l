    /*  
        Keano Gottlicher, CS5300 Spring 2016
        HW1 - Lexical Analysis for CPSL
        See Readme.txt for compiler instructions.
    */
%{
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <vector>
#define YY_DECL extern "C" int yylex()
#include "gottlicher_parser.cpp"

/*yyFlexLexer fl;*/

void printKeyword(std::string s)
{
    std::cout << "Found keyword : " << s << " at line : " << yylineno << std::endl;
}

void printOperator(std::string s)
{
    std::cout << "Found operator : " << s << " at line : " << yylineno << std::endl;    
}

void printIdentifier(std::string s)
{
    std::cout << "Found identifier: " << s << " at line : " << yylineno << std::endl;
}

void printIntLiteral(std::string type, int value)
{
    std::cout << "Found integer literal in base: " << type.c_str() << " ,value (dec):   " << value << " at line : " << yylineno << std::endl;
}

void printStringLiteral(std::string s)
{
    std::cout << "Found string literal: " << s << " at line: " << yylineno << std::endl;
}

void printCharLiteral(char c)
{
    std::cout << "Found character literal: " << c << " at line: " << yylineno << std::endl;
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
    boost::erase_all(s,"\n");
    std::cout << "Found comment with content: " << s << " at line: " << yylineno << std::endl;
}

void printError(std::string s)
{
    std::cout << "Found unknow character (error): " << s << " at line: " << yylineno << std::endl;
}
%}
/* options */

letter [a-zA-Z]
digit [0-9]
%option noyywrap
%option yylineno
/*%option c++*/
%%

     /* keywords */
array { return ArrayTok; }
begin { return  BeginTok; }
chr { return ChrTok; }
const { return ConstTok; }
do { return DoTok; }
downto { return DowntoTok; }
else { return ElseTok; }
elseif { return ElseifTok; }
end { return EndTok; }
for { return ForTok; }
forward { return ForwardTok; }
function { return FunctionTok; }
if { return IfTok; }
of { return OfTok; }
ord { return OrdTok; }
pred { return PredTok; }
procedure { return ProcedureTok; }
read { return ReadTok; }
record { return RecordTok; }
ref { return RefTok; }
repeat { return RepeatTok; }
return { return ReturnTok; }
stop { return StopTok; }
succ { return SuccTok; }
then { return ThenTok; }
to { return ToTok; }
type { return TypeTok; }
until { return UntilTok; }
var { return VarTok; }
while { return WhileTok; }
write { return WriteTok; }

    /* operators */
\+ { return PlusTok;}
\- { return MinusTok;}
\* { return MultiplyTok;}
\/ { return DivideTok;}
\& { return AndTok;}
\| { return OrTok;}
\~ { return NotTok;}
\= { return EqualsTok;} 
\<> { return LessGreaterTok;}
\< { return LessThanTok;}
\<= { return LessEqualTok;}
\> { return GreaterTok;}
\>= { return GreaterEqualTok;}
\. { return DotTok;}
\, { return CommaTok;}
\: { return ColonTok;}
\; { return SemicolonTok;}
\( { return OpenParenTok;}
\) { return CloseParenTok;}
\[ { return OpenBrktTok;}
\] { return CloseBrktTok;}
\:= { return ColonEqualTok;}
\% { return PercentTok;}

    /* Identifier */
{letter}({letter}|{digit}|_)* {/*TODO set value hereyytext;*/ return IdentifierTok;}
    /* literals */
    
0x([0-9a-fA-F])+ {/*TODO set value here*/(int)strtol(yytext,NULL,0); return IntTok;}  //Here the language specification is vague whether a-f should be caps or no caps, so I match both
0({digit})+ {/*TODO set value here*/(int)strtol(yytext,NULL,8); return IntTok;}
0|([1-9]({digit})*) {/*TODO set value here*/ (int)strtol(yytext,NULL,10); return IntTok;}
\"[\x20-\x7e]+\" {/*TODO set value here*/cleanUpString(yytext); return StringTok;}
'([\x21-\x5b\x5d-\x7e]|(\\[\x21-\x7e]))' {/*TODO set value here*/cleanUpChar(yytext); return ChrTok;}
 
    /* Comments */
(\$.*\n)  {/*Comments, don't do anything printComment(yytext);*/ }
    /* other */
[ \n\t\r]+ {/*whitespace, nothing to do here*/}
. { printError(yytext);}

%%

int main(int argc, char *argv[])
{
    yylex();
    yyparse();
    return 0;
}