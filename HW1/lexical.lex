%{
#include <stdio.h>

void printResult(char* s, int lineNo)
{
    printf("Found: %s at line : %i",s,lineNo);
    /*printf("Found: " << s << " at line: " << lineNo << std::endl;*/
}
%}
%option noyywrap
%option yylineno
%%

     /* keywords */
array { printResult("array",yylineno); }
    /*begin {}
chr {}
const {}
do {}
downto {}
else {}
elseif {}
end {}
for {}
forward {}
function {}
if {}
of {}
ord {}
pred {}
procedure {}
read {}
record {}
ref {}
repeat {}
return {}
stop {}
succ {}
then {}
to {}
type {}
until {}
var {}
while {}
write {}*/

    /* operators */

    /* literals */



%%

int main(int argc, char *argv[])
{
    yylex();
    return 0;
}