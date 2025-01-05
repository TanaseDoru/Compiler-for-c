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

"(int)"             { return T_INT_CAST; }
"(float)"           { return T_FLOAT_CAST; }
"(double)"          { return T_DOUBLE_CAST; }

"if"                { return T_IF_KW; } 
"else"              { return T_ELSE_KW; }
"while"             { return T_WHILE_KW; } 

"printf(\""[[:print:]]+"\")"                        {yylval.str = strdup(yytext); return T_PRINTF_SIMPLE;}
"printf(\""[[:print:]]+"\","[[:print:]]+")"       {yylloc.first_line = lineNo; yylval.str = strdup(yytext); return T_PRINTF_PARAM;}
"scanf(\""[[:print:]]+"\", "[[:print:]]+")"       {yylloc.first_line = lineNo; yylval.str = strdup(yytext); return T_SCANF;}

"//"[^\n]*                          ; //Comentariu pe o linie
\/\*[^*]*\*+([^/*][^*]*\*+)*\/      ; // comentariu pe mai multe linii

"=="                {return T_EQ; }
"!="                {return T_NEQ; }
"<="                {return T_LE; }
">="                {return T_GE; }

{ID}                            { yylloc.first_line = lineNo; yylval.str = strdup(yytext); return T_IDENTIFIER; }
{DOUBLE}f|{INTEGER}f            { yylloc.first_line = lineNo; yytext[yyleng - 1] = '\0'; yylval.fval = atof(yytext); return T_FLOAT_VAL; }
{INTEGER}                       { yylloc.first_line = lineNo; yylval.intval = atoi(yytext); return T_INTEGER_VAL; }
{DOUBLE}                        { yylloc.first_line = lineNo; yylval.dval = atof(yytext); return T_DOUBLE_VAL; }
[\n]                            {lineNo++; yylloc.first_line = lineNo;}
[\t ]             ;  
.                   { return yytext[0]; }  
%%