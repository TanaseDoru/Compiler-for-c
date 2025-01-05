/**************************************************/
//                  STACK MACHINE
/**************************************************/
#define MAX_INSTRUCTIONS 1024
#define MAX_STACK 1024

#ifndef DEBUGGER
#define DEBUGGER 2
#endif

#include <string.h>
#include "VTR.h"
#include "utils.h"
typedef enum opCodeType
{
    DECL,
    STORE,
    DATA,
    ADD,
    SUB,
    MUL,
    DIV,
    EQ,
    LE,
    LT,
    GE,
    GT,
    CONVERT,
    CHECK,
    HALT,
    NEQ,
    PRINTF,
    SCANF,
    JMP_FALSE,
    GOTO,
    INC_SCOPE,
    DEC_SCOPE,
    RET,
    CAST
} opCodeType_t;

char *opCodeName[] = {"Decl", "Store", "Push",
                      "ADD", "SUB", "MUL", "DIV", "EQ", "LE", "LT",
                      "GE", "GT", "Convert", "Check", "HALT", "NEQ",
                      "Printf", "Scanf", "Jmp_false", "goto", "IncScope",
                      "DecScope", "Return", "Cast"};

struct instruction
{
    enum opCodeType opCode;
    char buffer[1024];
    double value;
    int style; // -1 - none; 0 - use buffer; 1 - use value; 2 - use both

    int currentLine;
};

struct lbs // Pentru if si while
{
    int forGoto;
    int forJmpFalse;
};

struct lbs *newLbRec()
{
    return (struct lbs *)malloc(sizeof(struct lbs));
}

struct instruction instructionVector[MAX_INSTRUCTIONS];

struct stackStruct
{
    double val;
    enum varType type;
};
typedef struct stackStruct stackStruct;

stackStruct stack[MAX_STACK] = {}; // Stack of values
int top = -1;                      // Top of stack
int pc = 0;                        // Program counter
int instructionIndex = 0;          // index pentru instructionVector
int entryPoint = -1;

void fetchExecuteCycle()
{
    struct instruction ir;
    varRecord *ptr;
    if (entryPoint == -1)
    {
        printf("Error: No main function found\n");
        return;
    }
    pc = entryPoint;
    do
    {

        // Fetch
        ir = instructionVector[pc++];

        if (DEBUGGER >= 2)
        {
            printf("Executing(%d): %s str = %s value = %lg style = %d line = %d\n", pc - 1,
                   opCodeName[(int)ir.opCode], ir.buffer, ir.value, ir.style, ir.currentLine);
        }

        if (DEBUGGER == 3)
        {
            printf("Stack:");
            for (int i = 0; i <= top; i++)
            {
                printf("%lg ", stack[i].val);
            }
            printf("\n");
        }

        // Execute
        switch (ir.opCode)
        {
        case DECL:
            ptr = addVar(ir.buffer, ir.value);
            if (ptr == NULL)
            {
                printf("line %d: Previous declaration of variable %s\n", ir.currentLine, ir.buffer);
                ir.opCode = HALT;
            }
            break;

        case DATA:
            if (ir.style == 0)
            {
                ptr = getVar(ir.buffer);
                if (ptr == NULL)
                {
                    printf("line %d: Variable not declared %s\n", ir.currentLine, ir.buffer);
                    ir.opCode = HALT;
                    break;
                }
                stack[++top].val = ptr->value;
                stack[top].type = ptr->type;
            }
            else
            {
                stack[++top].val = ir.value;
                if (strcmp("double", ir.buffer) == 0)
                {
                    stack[top].type = t_double;
                }
                else if (strcmp("int", ir.buffer) == 0)
                {
                    stack[top].type = t_integer;
                }
                else if (strcmp("float", ir.buffer) == 0)
                {
                    stack[top].type = t_float;
                }
            }
            break;
        case STORE:
            if (top < 0)
            {
                printf("Line %d: ERROR: stack index is below 0\n", ir.currentLine);
                ir.opCode = HALT;
                break;
            }
            ptr = getVar(ir.buffer);

            if (ptr == NULL)
            {
                printf("line %d: Variable not declared %s\n", ir.currentLine, ir.buffer);
                ir.opCode = HALT;
                break;
            }
            if (ptr->type != stack[top].type)
            {
                printf("Line %d: Different variable type used for %s.\n", ir.currentLine, ptr->name);
                ir.opCode = HALT;
                break;
            }
            ptr->value = stack[top--].val;
            break;
        case CAST:
            if (top < 0)
            {
                printf("Line %d: ERROR: stack index is below 0\n", ir.currentLine);
                ir.opCode = HALT;
                break;
            }

            stack[top].type = ir.value;
            break;
        case PRINTF:
            if (ir.value == 0) // PRINTF_SIMPLE (only format)
            {
                char buffer[1024] = "";
                strcpy(buffer, ir.buffer + strlen("printf(\"")); // eliminare printf(" de la inceput
                buffer[strlen(buffer) - 2] = '\0';               // eliminare ") de la final
                for (int i = 0; i < strlen(buffer); i++)         // afisare manuala pentru ca \n sa mearga
                {
                    if (buffer[i] == '\\')
                    {
                        handleBackSlashForBuffer(buffer[i + 1]);
                        i++;
                        continue;
                    }
                    printf("%c", buffer[i]);
                }
            }
            if (ir.value == 1) // PRINTF_PARAM (format and parameters)
            {
                char buffer[1024];
                char varName[1024] = "";
                strcpy(buffer, ir.buffer + strlen("printf(\"")); // eliminare printf(" de la inceput
                char *p = strrchr(buffer, '\"');
                p += 2;                                          // eliminare ",
                int formatSize = strlen(buffer) - strlen(p) - 2; //-2 pentru ca am facut p += 2
                for (int i = 0; i < formatSize && buffer[i] != '\"'; i++)
                {
                    if (buffer[i] == '%')
                    {
                        varRecord *ptr = NULL;
                        while (p[0] == ' ')
                            p++;
                        i++;
                        int j = 0;
                        strcpy(varName, "");
                        switch (buffer[i])
                        {
                        case 'd':
                            while (p[0] != ',' && p[0] != ')')
                            {
                                varName[j++] = p[0];
                                p++;
                            }

                            varName[j] = '\0';
                            ptr = getVar(varName);
                            if (ptr == 0)
                            {
                                printf("line %d: Identifier %s not declared.\n", ir.currentLine, varName);
                                ir.opCode = HALT;
                                break;
                            }
                            printf("%d", (int)getVar(varName)->value);
                            break;
                        case 'f':
                            while (p[0] != ',' && p[0] != ')')
                            {
                                varName[j++] = p[0];
                                p++;
                            }
                            varName[j] = '\0';
                            ptr = getVar(varName);
                            if (ptr == 0)
                            {
                                printf("line %d: Identifier %s not declared.\n", ir.currentLine, varName);
                                ir.opCode = HALT;
                                break;
                            }
                            printf("%f", (float)getVar(varName)->value);
                            break;
                        case 'l':
                            i++;
                            if (buffer[i] != 'f')
                            {
                                printf("line %d: Symbol not recognized by %% \n", ir.currentLine);
                                ir.opCode = HALT;
                                break;
                            }
                            while (p[0] != ',' && p[0] != ')')
                            {
                                varName[j++] = p[0];
                                p++;
                            }
                            varName[j] = '\0';
                            ptr = getVar(varName);
                            if (ptr == 0)
                            {
                                printf("line %d: Identifier %s not declared.\n", ir.currentLine, varName);
                                ir.opCode = HALT;
                                break;
                            }
                            printf("%lf", getVar(varName)->value);
                            break;
                        default:
                            printf("line %d: Symbol not recognized by %% \n", ir.currentLine);
                            ir.opCode = HALT;
                            break;
                        }
                        j = 0;
                        p++;
                        continue;
                    }
                    if (buffer[i] == '\\')
                    {
                        i++;
                        handleBackSlashForBuffer(buffer[i]);
                        continue;
                    }
                    printf("%c", buffer[i]);
                }
            }
            fflush(0);
            break;
        case SCANF:
            char buffer[1024];
            char buf[245];
            double val = 0;
            char varName[1024] = "";
            strcpy(buffer, ir.buffer + strlen("scanf(\"")); // eliminare scnaf(" de la inceput
            char *p = strrchr(buffer, '\"');
            p += 2;                                          // eliminare ",
            int formatSize = strlen(buffer) - strlen(p) - 2; //-2 pentru ca am facut p += 2
            for (int i = 0; i < formatSize && buffer[i] != '\"'; i++)
            {
                if (buffer[i] == '%')
                {
                    while (p[0] == ' ')
                        p++;
                    i++;
                    int j = 0;
                    strcpy(varName, "");
                    if (p[0] != '&')
                    {
                        ir.opCode = HALT;
                        printf("line %d: & not used, could not read value\n", ir.currentLine);
                    }
                    p++;
                    varRecord *ptr = NULL;
                    switch (buffer[i])
                    {
                    case 'd':
                        while (p[0] != ',' && p[0] != ')')
                        {
                            varName[j++] = p[0];
                            p++;
                        }
                        scanf("%lf", &val);
                        varName[j] = '\0';
                        ptr = getVar(varName);
                        if (ptr == 0)
                        {
                            printf("line %d: Identifier %s not declared.\n", ir.currentLine, varName);
                            ir.opCode = HALT;
                            break;
                        }
                        ptr->value = (int)val;
                        break;
                    case 'f':
                        while (p[0] != ',' && p[0] != ')')
                        {
                            varName[j++] = p[0];
                            p++;
                        }
                        varName[j] = '\0';
                        ptr = getVar(varName);
                        if (ptr == 0)
                        {
                            printf("line %d: Identifier %s not declared.\n", ir.currentLine, varName);
                            ir.opCode = HALT;
                            break;
                        }
                        scanf("%s", buf);
                        if (buf[strlen(buf) - 1] == 'f')
                        {
                            buf[strlen(buf) - 1] = '\0';
                        }
                        else
                        {
                            printf("\nWrong type for variable %s\n", varName);
                            ir.opCode = HALT;
                            break;
                        }
                        ptr->value = (float)atof(buf);
                        break;
                    case 'l':
                        i++;
                        if (buffer[i] != 'f')
                        {
                            ir.opCode = HALT;
                            printf("line %d: Symbol not recognized by %% \n", ir.currentLine);
                            break;
                        }
                        while (p[0] != ',' && p[0] != ')')
                        {
                            varName[j++] = p[0];
                            p++;
                        }
                        scanf("%lf", &val);
                        varName[j] = '\0';
                        ptr = getVar(varName);
                        if (ptr == 0)
                        {
                            printf("line %d: Identifier %s not declared.\n", ir.currentLine, varName);
                            ir.opCode = HALT;
                            break;
                        }
                        ptr->value = (double)val;
                        break;
                    default:
                        printf("line %d: Symbol not recognized by %% \n", ir.currentLine);
                        ir.opCode = HALT;
                        break;
                    }
                    p++;
                    j = 0;
                    continue;
                }
                else if (buffer[0] == ' ')
                {
                    continue;
                }
                else
                {
                    ir.opCode = HALT;
                    printf("line %d: Character not recognized by scnaf, please only use %%\n", ir.currentLine);
                }
            }
            break;
        case GOTO:
            pc = ir.value;
            break;
        case JMP_FALSE:
            if (stack[top--].val == 0)
                pc = ir.value;
            break;
        case RET:
            if (top == -1 || (top == 0 && strcmp(ir.buffer, "void") != 0)) // daca nu mai avem adresa de return si daca functia nu este void atunci programul e gata
            {
                break;
            }
            if (strcmp(ir.buffer, "void") == 0)
            {
                pc = stack[top--].val;
                break;
            }
            ir.value = stack[top - 1].val;
            stack[top - 1] = stack[top];
            top--;
            pc = ir.value;
            break;
        case INC_SCOPE:
            increaseScope();
            break;
        case DEC_SCOPE:
            decreaseScope();
            break;
        case ADD:
            stack[top - 1].val = stack[top].val + stack[top - 1].val;
            if (stack[top].type == t_double)
                stack[top - 1].type = t_double;
            if (stack[top].type == t_float && stack[top - 1].type != t_double)
                stack[top - 1].type = t_float;
            top--;
            break;
        case SUB:
            stack[top - 1].val = stack[top - 1].val - stack[top].val;
            if (stack[top].type == t_double)
                stack[top - 1].type = t_double;
            if (stack[top].type == t_float && stack[top - 1].type != t_double)
                stack[top - 1].type = t_float;
            top--;
            break;
        case MUL:
            stack[top - 1].val = stack[top].val * stack[top - 1].val;
            if (stack[top].type == t_double)
                stack[top - 1].type = t_double;
            if (stack[top].type == t_float && stack[top - 1].type != t_double)
                stack[top - 1].type = t_float;
            top--;
            break;
        case DIV:
            if (stack[top].val == 0)
            {
                printf("line %d: Division by 0 not possible\n", ir.currentLine);
                ir.opCode = HALT;
                break;
            }
            stack[top - 1].val = stack[top - 1].val / stack[top].val;
            if (stack[top].type == t_double)
                stack[top - 1].type = t_double;
            if (stack[top].type == t_float && stack[top - 1].type != t_double)
                stack[top - 1].type = t_float;
            top--;
            break;
        case LT:
            stack[top - 1].val = stack[top - 1].val < stack[top].val;
            if (stack[top].type == t_double)
                stack[top - 1].type = t_double;
            if (stack[top].type == t_float && stack[top - 1].type != t_double)
                stack[top - 1].type = t_float;
            top--;
            break;
        case LE:
            stack[top - 1].val = stack[top - 1].val <= stack[top].val;
            if (stack[top].type == t_double)
                stack[top - 1].type = t_double;
            if (stack[top].type == t_float && stack[top - 1].type != t_double)
                stack[top - 1].type = t_float;
            top--;
            break;
        case GT:
            stack[top - 1].val = stack[top - 1].val > stack[top].val;
            if (stack[top].type == t_double)
                stack[top - 1].type = t_double;
            if (stack[top].type == t_float && stack[top - 1].type != t_double)
                stack[top - 1].type = t_float;
            top--;
            break;
        case GE:
            stack[top - 1].val = stack[top - 1].val >= stack[top].val;
            if (stack[top].type == t_double)
                stack[top - 1].type = t_double;
            if (stack[top].type == t_float && stack[top - 1].type != t_double)
                stack[top - 1].type = t_float;
            top--;
            break;
        case EQ:
            stack[top - 1].val = stack[top].val == stack[top - 1].val;
            if (stack[top].type == t_double)
                stack[top - 1].type = t_double;
            if (stack[top].type == t_float && stack[top - 1].type != t_double)
                stack[top - 1].type = t_float;
            top--;
            break;
        case NEQ:
            stack[top - 1].val = stack[top].val != stack[top - 1].val;
            if (stack[top].type == t_double)
                stack[top - 1].type = t_double;
            if (stack[top].type == t_float && stack[top - 1].type != t_double)
                stack[top - 1].type = t_float;
            top--;
            break;
        }
    } while (ir.opCode != HALT);
}

int reserveLoc()
{
    return instructionIndex++;
}

void genCode(opCodeType_t opCode, char *buffer, double value, int style, int line)
{
    instructionVector[instructionIndex].opCode = opCode;
    instructionVector[instructionIndex].value = value;
    instructionVector[instructionIndex].style = style;
    instructionVector[instructionIndex].currentLine = line;

    strcpy(instructionVector[instructionIndex++].buffer, buffer);
}

void printAllInstructions()
{
    printf("\n****************PRINTING INSTRUCTIONS**************\n");
    struct instruction ir;
    printf("Index\tLine\tInstrName\tValues\n");
    for (int i = 0; i < instructionIndex; i++)
    {
        printf("%d\t", i);
        ir = instructionVector[i];
        if (ir.style == -1)
        {
            printf("%d\t%s\n", ir.currentLine, opCodeName[(int)ir.opCode]);
        }
        else if (ir.style == 0)
        {
            printf("%d\t%s\t\tstr: %s\n", ir.currentLine, opCodeName[(int)ir.opCode], ir.buffer);
        }
        else if (ir.style == 1)
        {
            printf("%d\t%s\t\tvalue: %lg\n", ir.currentLine, opCodeName[(int)ir.opCode], ir.value);
        }
        else
            printf("%d\t%s\t\tstr: %s value: %lg\n", ir.currentLine, opCodeName[(int)ir.opCode],
                   ir.buffer, ir.value);
    }
    printf("**************INSTRUCTIONS PRINTED************\n\n");
}

void backPatch(int addr, opCodeType_t opCode, char *buffer, double value, int style, int line)
{
    instructionVector[addr].opCode = opCode;
    instructionVector[addr].value = value;
    instructionVector[addr].style = style;
    instructionVector[addr].currentLine = line;

    strcpy(instructionVector[addr].buffer, buffer);
}

int getCurrentIndex()
{
    return instructionIndex;
}