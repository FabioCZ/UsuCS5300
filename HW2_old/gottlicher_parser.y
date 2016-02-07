%{
    #include <iostream>
    extern "C" int yylex();
    extern "C" int yyparse();
    void yyerror(const char*);
%}

%error-verbose
%debug

%token ArrayTok
%token BeginTok
%token ChrTok
%token ConstTok
%token DoTok
%token DowntoTok
%token ElseTok
%token ElseifTok
%token EndTok
%token ForTok
%token ForwardTok
%token FunctionTok
%token IfTok
%token OfTok
%token OrdTok
%token PredTok
%token ProcedureTok
%token ReadTok
%token RecordTok
%token RefTok
%token RepeatTok
%token ReturnTok
%token StopTok
%token SuccTok
%token ThenTok
%token ToTok
%token TypeTok
%token UntilTok
%token VarTok
%token WhileTok
%token WriteTok


%token PlusTok
%token MinusTok
%token MultiplyTok
%token DivideTok
%token AndTok
%token OrTok
%token NotTok
%token EqualsTok
%token LessGreaterTok
%token LessThanTok
%token LessEqualTok
%token GreaterTok
%token GreaterEqualTok
%token DotTok
%token CommaTok
%token ColonTok
%token SemicolonTok
%token OpenParenTok
%token CloseParenTok
%token OpenBrktTok
%token CloseBrktTok
%token ColonEqualTok
%token PercentTok

%token IdentifierTok

%token IntTok
%token StringTok
%token CharTok
 
%%
Application : ApplicationStart Code DotTok {};
ApplicationStart : {};
Code : {};
%%
void yyerror(const char* errMsg)
{
    std::cout << "Bison error: " << errMsg << std::endl;
}