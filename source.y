%{
    #define DEBUGGER 1      // 0 - no debugger, 1 - print instructions and variables; 2 - print every instruction executed 3 - also show stack
    
    #include <stdio.h>
    #include <stdlib.h>
    #include "CG.h"
    #include "SM.h"
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
    int isActiveCast = 0; // Folosit pentru a verifica daca se face cast, daca da, atunci nu se va da push la 2 valori(Una de primul tip si a doua de tipul cast-ului)

    enum varType currentType;    
%}

/**********************************
            DATA TYPES
**********************************/

%union {int intval; char *str; double dval; struct lbs *lbVal; float fval;}

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
%token T_INT_CAST T_FLOAT_CAST T_DOUBLE_CAST
%token <lbVal> T_IF_KW T_WHILE_KW
%token T_ELSE_KW
%token T_VOID_KW
%token T_RETURN
%token T_COMM
%token T_ERROR
%token <str> T_PRINTF_PARAM
%token <str> T_PRINTF_SIMPLE
%token <str> T_SCANF
%token <intval> T_INTEGER_VAL
%token <str> T_IDENTIFIER
%token <dval> T_DOUBLE_VAL
%token <fval> T_FLOAT_VAL

%left '+' '-' T_EQ T_LE T_GE T_NEQ '>' '<'
%left '*' '/'



/**********************************
            GRAMMAR RULES
**********************************/

%%

program:
    function_declaration functions
    // T_INT_KW T_MAIN                         {entryPoint = getCurrentIndex();}
    // '(' ')' '{' instructions 
    // '}'                                     {genCode(HALT, "", 0, -1, @1.first_line);}
    | instructions
    | T_ERROR                                {errors++;}
    ;

functions:
    | functions function_declaration
function_declaration:  
    T_VOID_KW T_IDENTIFIER                       {
                                                if(strcmp($2, "main") == 0) 
                                                    entryPoint = getCurrentIndex(); 
                                                functionRecord*ptr = addFunction($2, getCurrentIndex());
                                                if(ptr == NULL)
                                                {
                                                    errors++;
                                                    printf("Line %d: Function %s already defined.\n",@1.first_line, $2);
                                                    break;
                                                }
                                                ptr->type = currentType; 
                                                strcpy(currentfunction, $2);
                                            }
    '('                                     {genCode(INC_SCOPE, "", 0, -1, @1.first_line); increaseScope();}
    parameter_list ')'                  
    '{'                                     {
                                                
                                            }
     instructions 
     '}'                                    {
                                                
                                                genCode(DEC_SCOPE, "", 0, -1, @1.first_line);
                                                decreaseScope();
                                                genCode(RET, "void", 0, 0, @1.first_line);
                                                if(strcmp(currentfunction, "main")==0)
                                                    genCode(HALT, "", 0, -1, @1.first_line);
                                            }
    | type T_IDENTIFIER                       {
                                                if(strcmp($2, "main") == 0) 
                                                    entryPoint = getCurrentIndex(); 
                                                functionRecord*ptr = addFunction($2, getCurrentIndex());
                                                if(ptr == NULL)
                                                {
                                                    errors++;
                                                    printf("Line %d: Function %s already defined.\n",@1.first_line, $2);
                                                    break;
                                                }
                                                strcpy(currentfunction, $2);
                                            }
    '('                                     {genCode(INC_SCOPE, "", 0, -1, @1.first_line); increaseScope();}
    parameter_list ')'                  
    '{'                                     {
                                                
                                            }
     instructions 
     '}'                                    {
                                                
                                                genCode(DEC_SCOPE, "", 0, -1, @1.first_line);
                                                decreaseScope();
                                                genCode(RET, "", 0, -1, @1.first_line);
                                                if(strcmp(currentfunction, "main")==0)
                                                    genCode(HALT, "", 0, -1, @1.first_line);
                                            }
;

parameter_list:
    | type T_IDENTIFIER parameter_list_tail         {
                                                        genCode(DECL, $2, 0, 0, @1.first_line); 
                                                        genCode(STORE, $2, 0, 0, @1.first_line); 
                                                        varRecord* ptr = addVar($2, currentType);
                                                        if(ptr == NULL) 
                                                        {
                                                            printf("line %d: Previous declaration of variable %s\n", @1.first_line, $2); 
                                                            errors++;
                                                            break;
                                                        }
                                                    }//addParamsToFunction(currentfunction, $2, currentType);}
;

parameter_list_tail:
    | ',' type T_IDENTIFIER parameter_list_tail {
                                                    genCode(DECL, $3, 0, 0, @1.first_line); 
                                                    genCode(STORE, $3, 0, 0, @1.first_line); 
                                                    varRecord* ptr = addVar($3, currentType);
                                                    if(ptr == NULL) 
                                                    {
                                                        printf("line %d: Previous declaration of variable %s\n", @1.first_line, $3); 
                                                        errors++;
                                                        break;
                                                    }
                                                }
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
                                                        printf("Line %d: Function \"%s\" not found\n", @1.first_line, $1);
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
    '{'                                     {genCode(INC_SCOPE, "", 0, -1, @1.first_line); increaseScope();}
    instructions                        
    '}'                                     {genCode(DEC_SCOPE, "", 0, -1, @1.first_line); decreaseScope(); genCode(GOTO, "", $1->forGoto, 1, @1.first_line); backPatch($1->forJmpFalse, JMP_FALSE, "", getCurrentIndex(), 1, @1.first_line);}
    instructions
    |'{'                                    {genCode(INC_SCOPE, "", 0, -1, @1.first_line); increaseScope();}
    instructions
    '}'                                     {genCode(DEC_SCOPE, "", 0, -1, @1.first_line); decreaseScope(); }
    instructions
    ;

instruction:
    | T_COMM
    | function_call
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
                                                genCode(PRINTF, strdup($1), 1, 2, @1.first_line);
                                                // if(errors > 0 || shouldExecute == 0) break;
                                                char buffer[1024];
                                                char varName[1024] = "";
                                                strcpy(buffer, $1 + strlen("printf(\""));  // eliminare printf(" de la inceput
                                                char* p = strrchr(buffer, '\"');
                                                p+=2;                           //eliminare ",
                                                int formatSize = strlen(buffer) - strlen(p) - 2;     //-2 pentru ca am facut p += 2
                                                int j;
                                                for(int i = 0; i < formatSize && buffer[i] != '\"' && errors == 0; i++)
                                                {
                                                    if(buffer[i] == '%')
                                                    {
                                                        varRecord* ptr = NULL;
                                                        while(p[0] == ' ') p++;
                                                        i++;
                                                        
                                                        switch(buffer[i])
                                                        {
                                                            case 'd':
                                                                while(p[0] != ',' && p[0] != ')')
                                                                {
                                                                    varName[j++] = p[0];
                                                                    p++;
                                                                }
                                                                varName[j] = '\0';
                                                                ptr = getVar(varName);
                                                                if(ptr == 0)
                                                                {
                                                                    printf("line %d: Identifier %s not declared.\n", @1.first_line, varName); 
                                                                    errors++;
                                                                    break;
                                                                }
                                                                if(ptr->type != t_integer)
                                                                {
                                                                    printf("Line %d: Identifier %s has wrong type.\n", @1.first_line, varName);
                                                                    errors++;
                                                                    break;
                                                                }
                                                            break;
                                                            case 'f':
                                                                while(p[0] != ',' && p[0] != ')')
                                                                {
                                                                    varName[j++] = p[0];
                                                                    p++;
                                                                }
                                                                varName[j] = '\0';
                                                                ptr = getVar(varName);
                                                                if(ptr == 0)
                                                                {
                                                                    printf("line %d: Identifier %s not declared.\n", @1.first_line, varName); 
                                                                    errors++;
                                                                    break;
                                                                }
                                                                if(ptr->type != t_float)
                                                                {
                                                                    printf("Line %d: Identifier %s has wrong type.\n", @1.first_line, varName);
                                                                    errors++;
                                                                    break;
                                                                }
                                                                break;
                                                            case 'l':
                                                                i++;
                                                                if(buffer[i] != 'f')
                                                                {
                                                                    errors++;
                                                                    printf("line %d: Symbol not recognized by %% \n", @1.first_line);
                                                                    break;
                                                                }
                                                                while(p[0] != ',' && p[0] != ')')
                                                                {
                                                                    varName[j++] = p[0];
                                                                    p++;
                                                                }
                                                                varName[j] = '\0';
                                                                ptr = getVar(varName);
                                                                if(ptr == 0)
                                                                {
                                                                    printf("line %d: Identifier %s not declared.\n", @1.first_line, varName); 
                                                                    errors++;
                                                                    break;
                                                                }
                                                                if(ptr->type != t_double)
                                                                {
                                                                    printf("Line %d: Identifier %s has wrong type.\n", @1.first_line, varName);
                                                                    errors++;
                                                                    break;
                                                                }
                                                                break;
                                                            default:
                                                            printf("line %d: Symbol not recognized by %% \n", @1.first_line);
                                                            errors++;
                                                            break;
                                                        }
                                                        j=0;
                                                        p++;
                                                        continue;

                                                    }
                                                    if(buffer[i] == '\\')
                                                    {
                                                        i++;
                                                        handleBackSlashForBuffer(buffer[i]);
                                                        continue;
                                                    }
                                                }
                                            }
    | T_SCANF                               {
                                                genCode(SCANF, strdup($1), 0, 0, @1.first_line);
                                                // if(errors > 0 || shouldExecute == 0) break;
                                                char buffer[1024];
                                                double val=0;
                                                char varName[1024] = "";
                                                strcpy(buffer, $1 + strlen("scanf(\""));  // eliminare scnaf(" de la inceput
                                                char* p = strrchr(buffer, '\"');
                                                p+=2;                           //eliminare ",
                                                int formatSize = strlen(buffer) - strlen(p) - 2;     //-2 pentru ca am facut p += 2
                                                for(int i = 0; i < formatSize && buffer[i] != '\"' && errors == 0; i++)
                                                {
                                                    if(buffer[i] == '%')
                                                    {
                                                        while(p[0] == ' ') p++;
                                                        i++;
                                                        int j = 0;
                                                        strcpy(varName, "");
                                                        if(p[0] != '&')
                                                        {
                                                            errors++;
                                                            printf("line %d: & not used, could not read value\n", @1.first_line);
                                                        }
                                                        p++;
                                                        varRecord* ptr = NULL;
                                                        switch(buffer[i])
                                                        {
                                                            case 'd':
                                                                while(p[0] != ',' && p[0] != ')')
                                                                {
                                                                    varName[j++] = p[0];
                                                                    p++;
                                                                }
                                                                ptr = getVar(varName);
                                                                if(ptr == 0)
                                                                {
                                                                    printf("line %d: Identifier %s not declared.\n", @1.first_line, varName); 
                                                                    errors++;
                                                                    break;
                                                                }
                                                                if(ptr->type != t_integer)
                                                                {
                                                                    printf("Line %d: Identifier %s has wrong type.\n", @1.first_line, varName);
                                                                    errors++;
                                                                    break;
                                                                }
                                                            break;
                                                            case 'f':
                                                                while(p[0] != ',' && p[0] != ')')
                                                                {
                                                                    varName[j++] = p[0];
                                                                    p++;
                                                                }
                                                                ptr = getVar(varName);
                                                                if(ptr == 0)
                                                                {
                                                                    printf("line %d: Identifier %s not declared.\n", @1.first_line, varName); 
                                                                    errors++;
                                                                    break;
                                                                }
                                                                if(ptr->type != t_float)
                                                                {
                                                                    printf("Line %d: Identifier %s has wrong type.\n", @1.first_line, varName);
                                                                    errors++;
                                                                    break;
                                                                }
                                                                break;
                                                            case 'l':
                                                                i++;
                                                                if(buffer[i] != 'f')
                                                                {
                                                                    errors++;
                                                                    printf("line %d: Symbol not recognized by %% \n", @1.first_line);
                                                                    break;
                                                                }
                                                                while(p[0] != ',' && p[0] != ')')
                                                                {
                                                                    varName[j++] = p[0];
                                                                    p++;
                                                                }
                                                                ptr = getVar(varName);
                                                                if(ptr == 0)
                                                                {
                                                                    printf("line %d: Identifier %s not declared.\n", @1.first_line, varName); 
                                                                    errors++;
                                                                    break;
                                                                }
                                                                if(ptr->type != t_double)
                                                                {
                                                                    printf("Line %d: Identifier %s has wrong type.\n", @1.first_line, varName);
                                                                    errors++;
                                                                    break;
                                                                }
                                                                break;
                                                            default:
                                                            printf("line %d: Symbol not recognized by %% \n", @1.first_line);
                                                            errors++;
                                                            break;
                                                        }
                                                        p++;
                                                        continue;
                                                    } else if (buffer[0] == ' ') {continue;}
                                                    else
                                                    {
                                                        errors++;
                                                        printf("line %d: Character not recognized by scnaf, please only use %%\n", @1.first_line);
                                                    }
                                                }
                                                
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
    | T_FLOAT_KW                            { currentType = t_float; }
    ;

variable_list:
    variable_declaration                                            
    | variable_declaration ',' variable_list                        
    ;

variable_declaration:
    T_IDENTIFIER                            { 
                                                genCode(DECL, $1, currentType, 2, @1.first_line);
                                                varRecord* ptr = addVar($1, currentType);  
                                                if(ptr == NULL) 
                                                {
                                                    printf("line %d: Previous declaration of variable %s\n", @1.first_line, $1); 
                                                    errors++;
                                                }
                                            }
    | T_IDENTIFIER '=' expression        {
                                            genCode(DECL, $1, currentType, 2, @1.first_line);
                                            genCode(STORE, $1, 0, 0, @1.first_line);
                                            varRecord* ptr = addVar($1, currentType);
                                            if(ptr == NULL) 
                                            {
                                                printf("line %d: Previous declaration of variable %s\n", @1.first_line, $1); 
                                                errors++;
                                                break;
                                            }
                                            // ptr->value = $3;
                                        }
    ;

variable_load: 
    T_IDENTIFIER '=' expression         {
                                            genCode(STORE, $1, 0, 0, @1.first_line);
                                            //if (shouldExecute == 0) break; 
                                            varRecord* ptr = getVar($1);
                                            if(ptr == NULL)
                                            {
                                                printf("Line %d: Identifier %s not declared.\n", @1.first_line, $1);
                                                errors++;
                                                break;
                                            }
                                            // ptr->value = $3;
                                        }
    ;

expression: T_IDENTIFIER                {
                                            
                                            // if (shouldExecute == 0) break;  
                                            varRecord* ptr = getVar($1);
                                            if(ptr == NULL)
                                            {
                                                printf("Line %d: Idendifier %s not declared.\n", @1.first_line, $1);
                                                errors++;
                                                break;
                                            }
                                            genCode(DATA, $1, ptr->type, 0, @1.first_line);

                                        }
    | T_DOUBLE_VAL                          {genCode(DATA, "double", $1, 1, @1.first_line);}
    | T_INTEGER_VAL                         {genCode(DATA, "int", (double)$1, 1, @1.first_line);}
    | T_FLOAT_VAL                           {genCode(DATA, "float", (double)$1, 1, @1.first_line);}
    | T_INT_CAST expression                 {genCode(CAST, varTypeName[t_integer], t_integer, 0, @1.first_line);}
    | T_FLOAT_CAST expression               {genCode(CAST, varTypeName[t_float], t_float, 0, @1.first_line);}
    | T_DOUBLE_CAST expression              {genCode(CAST, varTypeName[t_double], t_double, 0, @1.first_line);}
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
    | '(' expression ')'                    {/*if (shouldExecute == 0) break;*/ $$ = $2;}
    | function_call                         {
                                                
                                            }
    ;

%%

/**********************************
            MAIN FUNCTION
**********************************/

int main(int argc, char** argv)
{   
    currentState = parsing;
    char c;
    char buffer[1024];
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("Error opening file");
            return 1;
        }
    }
    else
    {
        printf("Doriti sa introduceti fisier de la tastatura? [y/n]\n");
        scanf("%c", &c);
    }
    if(c == 'y')
    {
        printf("Introduceti numele fisierului: ");
        scanf("%s", buffer);
        yyin = fopen(buffer, "r");
        if(!yyin)
        {
            perror("Error opening file");
            return 1;
        }
    }
    else if(argc == 1)
    {
        printf("Introduceti codul manual:\n");
    }
    yyparse();
    currentState = executing;
    printf("Parsing ended.\n");
    if(DEBUGGER)
    {
        printAllInstructions();
    }
    printf("-------------------STARTING CODE SEQUENCE--------------------\n\n");
    if(errors > 0)
    {
        printf("Code can not execute, detected %d errors.\n", errors);
    }
    else
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
