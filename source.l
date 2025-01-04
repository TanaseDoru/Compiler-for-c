%option noyywrap

%{
#include "source.tab.h"
#include <stdlib.h>
#include <stdio.h>
int lineNo = 1;
%}


ID          [a-zA-Z][a-zA-Z0-9]*
INTEGER     [0-9]+
DOUBLE      [0-9]+\.[0-9]+

%%
"int"               { return T_INT_KW; }
"float"             { return T_FLOAT_KW; }
"double"            { return T_DOUBLE_KW; }
"return"            { return T_RETURN; }
"void"              { return T_VOID_KW; }

"if"                { return T_IF_KW; } 
"else"              { return T_ELSE_KW; }
"while"             { return T_WHILE_KW; }  // De implementat

"printf(\""[[:print:]]+"\")"                        {yylval.str = strdup(yytext); return T_PRINTF_SIMPLE;}
"printf(\""[[:print:]]+"\","[a-zA-Z&*_0-9, ]+")"    {yylloc.first_line = lineNo; yylval.str = strdup(yytext); return T_PRINTF_PARAM;}
"scanf(\""[[:print:]]+"\", "[a-zA-Z&*_0-9, ]+")"    {yylloc.first_line = lineNo; yylval.str = strdup(yytext); return T_SCANF;}

"=="                {return T_EQ; }
"!="                {return T_NEQ; }
"<="                {return T_LE; }
">="                {return T_GE; }

{ID}                            { yylloc.first_line = lineNo; yylval.str = strdup(yytext); return T_IDENTIFIER; }
{INTEGER}                       { yylloc.first_line = lineNo; yylval.intval = atoi(yytext); return T_INTEGER_VAL; }
{DOUBLE}|{DOUBLE}f|{INTEGER}f   { yylloc.first_line = lineNo; yylval.dval = atof(yytext); return T_DOUBLE_VAL; }
[\n]                            {lineNo++; yylloc.first_line = lineNo;}
[\t ]             ;  
.                   { return yytext[0]; }  
%%