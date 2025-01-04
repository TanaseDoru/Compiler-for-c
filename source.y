%{
    #define DEBUGGER 1
    
    #include <stdio.h>
    #include <stdlib.h>
    #include "CG.h"
    #include "SM.h"
    #include "flowHeader.h"
    #include "utils.h"
    #include "functionHandler.h"
    #include "VTR.h"
    
    extern FILE* yyin;
    int noErrors = 0;
    int errors;
    int yylex();
    int yyerror(const char *msg);
    extern int lineNo;

    

    char currentfunction[256];

    enum varType currentType;    
%}

/**********************************
            DATA TYPES
**********************************/

%union {int intval; char *str; double dval; struct lbs *lbVal;}

/**********************************
            START TOKEN
**********************************/

%start program

/**********************************
                TOKENS
**********************************/

%token T_EQ T_LE T_GE T_NEQ
%type <dval> expression
%type <lbVal> midrule_lbs

%token T_INT_KW T_FLOAT_KW T_DOUBLE_KW
%token <lbVal> T_IF_KW T_WHILE_KW
%token T_ELSE_KW
%token T_VOID_KW
%token T_RETURN
%token T_ERROR
%token <str> T_PRINTF_PARAM
%token <str> T_PRINTF_SIMPLE
%token <str> T_SCANF
%token <intval> T_INTEGER_VAL
%token <str> T_IDENTIFIER
%token <dval> T_DOUBLE_VAL

%left '+' '-' T_EQ T_LE T_GE T_NEQ '>' '<'
%left '*' '/'



/**********************************
            GRAMMAR RULES
**********************************/

%%

program:
    functions function_declaration
    // T_INT_KW T_MAIN                         {entryPoint = getCurrentIndex();}
    // '(' ')' '{' instructions 
    // '}'                                     {genCode(HALT, "", 0, -1, @1.first_line);}
    | instructions
    | T_ERROR                                {errors++;}
    ;

functions:
    | functions function_declaration
function_declaration:                 
    type T_IDENTIFIER                       {
                                                if(strcmp($2, "main") == 0) 
                                                    entryPoint = getCurrentIndex(); 
                                                addFunction($2, getCurrentIndex())->type = currentType; 
                                                strcpy(currentfunction, $2);
                                            }
    '('                                     {genCode(INC_SCOPE, "", 0, -1, @1.first_line);}
    parameter_list ')'                  
    '{'                                     {
                                                
                                            }
     instructions 
     '}'                                    {
                                                
                                                genCode(DEC_SCOPE, "", 0, -1, @1.first_line);
                                                genCode(RET, "", 0, -1, @1.first_line);
                                                if(strcmp(currentfunction, "main")==0)
                                                    genCode(HALT, "", 0, -1, @1.first_line);
                                            }
;

parameter_list:
    | type T_IDENTIFIER parameter_list_tail         {genCode(DECL, $2, 0, 0, @1.first_line); genCode(STORE, $2, 0, 0, @1.first_line); }//addParamsToFunction(currentfunction, $2, currentType);}
;

parameter_list_tail:
    | ',' type T_IDENTIFIER parameter_list_tail {genCode(DECL, $3, 0, 0, @1.first_line); genCode(STORE, $3, 0, 0, @1.first_line); }
;

midrule_lbs:
                                                { $$ = (struct lbs*) newLbRec(); $$->forGoto = reserveLoc(); }
;

function_call:
    T_IDENTIFIER  midrule_lbs                    
    '(' argument_list 
    ')'                                         {
                                                    functionRecord* ptr = getFunction($1);
                                                    if(ptr == NULL)
                                                    {
                                                        printf("Line %d: Function not found\n", @1.first_line);
                                                        errors++;
                                                        break;
                                                    }
                                                    genCode(GOTO, "", getFunction($1)->functionIndex, 1, @1.first_line);
                                                    backPatch($2->forGoto, DATA, "", getCurrentIndex(), 1, @1.first_line);
                                                }
;


argument_list:
    | expression argument_list_tail             
;

argument_list_tail:
    | ',' expression argument_list_tail       
;

instructions:
    | instruction ';' instructions
    | T_IF_KW '(' expression ')'            {
                                                $1 = (struct lbs*) newLbRec();
                                                $1->forJmpFalse = reserveLoc();
                                                
                                                // if($3 != 0)
                                                // {
                                                //     currentIfCondition[ifCount++] = 1;
                                                //     shouldExecute = 1;
                                                // }
                                                // else
                                                // {
                                                //     currentIfCondition[ifCount++] = 0;
                                                //     shouldExecute = 0;
                                                // }
                                            }
    '{' instructions                        
    '}'                                     {  }//ifCount--; if(ifCount == 0) shouldExecute = 1;}
    T_ELSE_KW                               {$1->forGoto = reserveLoc();backPatch($1->forJmpFalse, JMP_FALSE, "", getCurrentIndex(), 1, @1.first_line); }
    '{' instructions
    '}'                                     { backPatch($1->forGoto, GOTO, "", getCurrentIndex(), 1, @1.first_line);}
    instructions   
    | T_WHILE_KW                            {
                                                $1 = (struct lbs*) newLbRec();
                                                $1->forGoto = getCurrentIndex();
                                            }
 
    '(' expression ')'                      {$1->forJmpFalse = reserveLoc();}
    '{'                                     {genCode(INC_SCOPE, "", 0, -1, @1.first_line);}
    instructions                        
    '}'                                     {genCode(DEC_SCOPE, "", 0, -1, @1.first_line); genCode(GOTO, "", $1->forGoto, 1, @1.first_line); backPatch($1->forJmpFalse, JMP_FALSE, "", getCurrentIndex(), 1, @1.first_line);}
    instructions
    |'{'                                    {genCode(INC_SCOPE, "", 0, -1, @1.first_line);}
    instructions
    '}'                                     {genCode(DEC_SCOPE, "", 0, -1, @1.first_line);}
    instructions
    ;

instruction:
    | T_RETURN expression
    | declarations
    | variable_load
    | T_PRINTF_SIMPLE                       {
                                                genCode(PRINTF, $1, 0, 3, @1.first_line);
                                                // if(errors > 0 || shouldExecute == 0) break;
                                                // char buffer[1024] = "";
                                                // strcpy(buffer, $1 + strlen("printf(\"")); // eliminare printf(" de la inceput
                                                // buffer[strlen(buffer) - 2] = '\0'; //eliminare ") de la final
                                                // for(int i = 0; i < strlen(buffer); i++) // afisare manuala pentru ca \n sa mearga
                                                // {
                                                //     if(buffer[i] == '\\')
                                                //     {
                                                //         handleBackSlashForBuffer(buffer[i+1]);
                                                //         i++;
                                                //         continue;
                                                //     }
                                                //     printf("%c", buffer[i]);
                                                // }
                                            }
    | T_PRINTF_PARAM                        {
                                                genCode(PRINTF, $1, 1, 2, @1.first_line);
                                                // if(errors > 0 || shouldExecute == 0) break;
                                                // char buffer[1024];
                                                // char varName[1024] = "";
                                                // strcpy(buffer, $1 + strlen("printf(\""));  // eliminare printf(" de la inceput
                                                // char* p = strchr(buffer, '\"');
                                                // p+=2;                           //eliminare ",
                                                // int formatSize = strlen(buffer) - strlen(p) - 2;     //-2 pentru ca am facut p += 2
                                                // for(int i = 0; i < formatSize && buffer[i] != '\"' && errors == 0; i++)
                                                // {
                                                //     if(buffer[i] == '%')
                                                //     {
                                                //         varRecord* ptr = NULL;
                                                //         while(p[0] == ' ') p++;
                                                //         i++;
                                                //         int j = 0;
                                                //         strcpy(varName, "");
                                                //         switch(buffer[i])
                                                //         {
                                                //             case 'd':
                                                //                 while(p[0] != ',' && p[0] != ')')
                                                //                 {
                                                //                     varName[j++] = p[0];
                                                //                     p++;
                                                //                 }

                                                //                 ptr = getVar(varName);
                                                //                 if(ptr == 0)
                                                //                 {
                                                //                     printf("line %d: Identifier %s not declared.\n", @1.first_line, varName); 
                                                //                     errors++;
                                                //                     break;
                                                //                 }
                                                //                 printf("%d",(int)getVar(varName)->value);
                                                //             break;
                                                //             case 'f':
                                                //                 while(p[0] != ',' && p[0] != ')')
                                                //                 {
                                                //                     varName[j++] = p[0];
                                                //                     p++;
                                                //                 }
                                                //                 ptr = getVar(varName);
                                                //                 if(ptr == 0)
                                                //                 {
                                                //                     printf("line %d: Identifier %s not declared.\n", @1.first_line, varName); 
                                                //                     errors++;
                                                //                     break;
                                                //                 }
                                                //                 printf("%f", (float)getVar(varName)->value);
                                                //                 break;
                                                //             case 'l':
                                                //                 i++;
                                                //                 if(buffer[i] != 'f')
                                                //                 {
                                                //                     errors++;
                                                //                     printf("line %d: Symbol not recognized by %% \n", @1.first_line);
                                                //                     break;
                                                //                 }
                                                //                 while(p[0] != ',' && p[0] != ')')
                                                //                 {
                                                //                     varName[j++] = p[0];
                                                //                     p++;
                                                //                 }
                                                //                 ptr = getVar(varName);
                                                //                 if(ptr == 0)
                                                //                 {
                                                //                     printf("line %d: Identifier %s not declared.\n", @1.first_line, varName); 
                                                //                     errors++;
                                                //                     break;
                                                //                 }
                                                //                 printf("%lf", getVar(varName)->value);
                                                //                 break;
                                                //             default:
                                                //             printf("line %d: Symbol not recognized by %% \n", @1.first_line);
                                                //             errors++;
                                                //             break;
                                                //         }


                                                //         p++;
                                                //         continue;

                                                //     }
                                                //     if(buffer[i] == '\\')
                                                //     {
                                                //         i++;
                                                //         handleBackSlashForBuffer(buffer[i]);
                                                //         continue;
                                                //     }
                                                //     printf("%c", buffer[i]);
                                                // }
                                            }
    | T_SCANF                               {
                                                genCode(SCANF, $1, 0, 0, @1.first_line);
                                                // if(errors > 0 || shouldExecute == 0) break;
                                                // char buffer[1024];
                                                // double val=0;
                                                // char varName[1024] = "";
                                                // strcpy(buffer, $1 + strlen("scanf(\""));  // eliminare scnaf(" de la inceput
                                                // char* p = strchr(buffer, '\"');
                                                // p+=2;                           //eliminare ",
                                                // int formatSize = strlen(buffer) - strlen(p) - 2;     //-2 pentru ca am facut p += 2
                                                // for(int i = 0; i < formatSize && buffer[i] != '\"' && errors == 0; i++)
                                                // {
                                                //     if(buffer[i] == '%')
                                                //     {
                                                //         while(p[0] == ' ') p++;
                                                //         i++;
                                                //         int j = 0;
                                                //         strcpy(varName, "");
                                                //         if(p[0] != '&')
                                                //         {
                                                //             errors++;
                                                //             printf("line %d: & not used, could not read value\n", @1.first_line);
                                                //         }
                                                //         p++;
                                                //         varRecord* ptr = NULL;
                                                //         switch(buffer[i])
                                                //         {
                                                //             case 'd':
                                                //                 while(p[0] != ',' && p[0] != ')')
                                                //                 {
                                                //                     varName[j++] = p[0];
                                                //                     p++;
                                                //                 }
                                                //                 scanf("%lf", &val);
                                                //                 ptr = getVar(varName);
                                                //                 if(ptr == 0)
                                                //                 {
                                                //                     printf("line %d: Identifier %s not declared.\n", @1.first_line, varName); 
                                                //                     errors++;
                                                //                     break;
                                                //                 }
                                                //                 ptr->value = (int)val;
                                                //             break;
                                                //             case 'f':
                                                //                 while(p[0] != ',' && p[0] != ')')
                                                //                 {
                                                //                     varName[j++] = p[0];
                                                //                     p++;
                                                //                 }
                                                //                 scanf("%lf", &val);
                                                //                 ptr = getVar(varName);
                                                //                 if(ptr == 0)
                                                //                 {
                                                //                     printf("line %d: Identifier %s not declared.\n", @1.first_line, varName); 
                                                //                     errors++;
                                                //                     break;
                                                //                 }
                                                //                 ptr->value = (float)val;
                                                //                 break;
                                                //             case 'l':
                                                //                 i++;
                                                //                 if(buffer[i] != 'f')
                                                //                 {
                                                //                     errors++;
                                                //                     printf("line %d: Symbol not recognized by %% \n", @1.first_line);
                                                //                     break;
                                                //                 }
                                                //                 while(p[0] != ',' && p[0] != ')')
                                                //                 {
                                                //                     varName[j++] = p[0];
                                                //                     p++;
                                                //                 }
                                                //                 scanf("%lf", &val);
                                                //                 ptr = getVar(varName);
                                                //                 if(ptr == 0)
                                                //                 {
                                                //                     printf("line %d: Identifier %s not declared.\n", @1.first_line, varName); 
                                                //                     errors++;
                                                //                     break;
                                                //                 }
                                                //                 ptr->value = (double)val;
                                                //                 break;
                                                //             default:
                                                //             printf("line %d: Symbol not recognized by %% \n", @1.first_line);
                                                //             errors++;
                                                //             break;
                                                //         }
                                                //         p++;
                                                //         continue;
                                                //     } else if (buffer[0] == ' ') {continue;}
                                                //     else
                                                //     {
                                                //         errors++;
                                                //         printf("line %d: Character not recognized by scnaf, please only use %%\n", @1.first_line);
                                                //     }
                                                // }
                                                
                                            }
    
    ;

declarations:
    declaration
    | declaration declarations
    ;

declaration:
    type variable_list                                  
    ;

type:
    T_INT_KW                                { currentType = t_integer; }
    | T_DOUBLE_KW                           { currentType = t_double; }
    | T_FLOAT_KW                            { currentType = t_double; }
    ;

variable_list:
    variable_declaration                                            
    | variable_declaration ',' variable_list                        
    ;

variable_declaration:
    T_IDENTIFIER                            { 
                                                genCode(DECL, $1, currentType, 2, @1.first_line);
                                                // varRecord* ptr = addVar($1, currentType);  
                                                // if(ptr == NULL) 
                                                // {
                                                //     printf("line %d: Previous declaration of variable %s\n", @1.first_line, $1); 
                                                //     errors++;
                                                // }
                                            }
    | T_IDENTIFIER '=' expression        {
                                            genCode(DECL, $1, currentType, 2, @1.first_line);
                                            genCode(STORE, $1, 0, 0, @1.first_line);
                                            // varRecord* ptr = addVar($1, currentType);
                                            // if(ptr == NULL) 
                                            // {
                                            //     printf("line %d: Previous declaration of variable %s\n", @1.first_line, $1); 
                                            //     errors++;
                                            //     break;
                                            // }
                                            // ptr->value = $3;
                                        }
    ;

variable_load: 
    T_IDENTIFIER '=' expression         {
                                            genCode(STORE, $1, 0, 0, @1.first_line);
                                            // if (shouldExecute == 0) break; 
                                            // varRecord* ptr = getVar($1);
                                            // if(ptr == NULL)
                                            // {
                                            //     printf("Line %d: Identifier %s not declared.\n", @1.first_line, $1);
                                            //     errors++;
                                            //     break;
                                            // }
                                            // ptr->value = $3;
                                        }
    ;

expression: T_IDENTIFIER                {
                                            genCode(DATA, $1, 0, 0, @1.first_line);
                                            // if (shouldExecute == 0) break;  
                                            // varRecord* ptr = getVar($1);
                                            // if(ptr == NULL)
                                            // {
                                            //     printf("Line %d: Idendifier %s not declared.\n", @1.first_line, $1);
                                            //     errors++;
                                            //     break;
                                            // }
                                            // $$ = ptr->value;
                                        }
    | T_DOUBLE_VAL                          {genCode(DATA, "", $1, 1, @1.first_line);}
    | T_INTEGER_VAL                         {genCode(DATA, "", (double)$1, 1, @1.first_line);}
    | expression '+' expression             {genCode(ADD, "", 0, -1, @1.first_line);  $$ = $1 + $3;}
    | expression '-' expression             {genCode(SUB, "", 0, -1, @1.first_line); $$ = $1 - $3;}
    | expression '*' expression             {genCode(MUL, "", 0, -1, @1.first_line);  $$ = $1 * $3;}
    | expression '/' expression             {genCode(DIV, "", 0, -1, @1.first_line);}
    | expression '<' expression             {genCode(LT, "", 0, -1, @1.first_line); $$ = $1 < $3;}
    | expression T_LE expression            {genCode(LE, "", 0, -1, @1.first_line); $$ = $1 <= $3;}
    | expression '>' expression             {genCode(GT, "", 0, -1, @1.first_line); $$ = $1 > $3;}
    | expression T_GE expression            {genCode(GE, "", 0, -1, @1.first_line); $$ = $1 >= $3;}
    | expression T_EQ expression            {genCode(EQ, "", 0, -1, @1.first_line); $$ = $1 == $3;}
    | expression T_NEQ expression           {genCode(NEQ, "", 0, -1, @1.first_line); $$ = $1 != $3;}
    | '(' expression ')'                    {if (shouldExecute == 0) break; $$ = $2;}
    | function_call                         {
                                                
                                            }
    ;

%%

/**********************************
            MAIN FUNCTION
**********************************/

int main(int argc, char** argv)
{   
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("Error opening file");
            return 1;
        }
    }
    yyparse();
    printf("Parsing ended.\n");
    if(DEBUGGER)
    {
        printAllInstructions();
    }
    printf("-------------------STARTING CODE SEQUENCE--------------------\n\n");
    fetchExecuteCycle();
    printf("\n\n------------------CODE ENDED-------------------\n");
    if(DEBUGGER)
    {
        //printf("IfCount= %d\n", ifCount);
        printAllVars();
    }
    return 0;
}

int yyerror(const char *msg)
{
    printf("Line %d: Error: %s\n",lineNo, msg);
    errors++;
    return 1;
}
