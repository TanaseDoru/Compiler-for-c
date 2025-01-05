/***********************************************************************/
//                VARIABLE TABLE RECORD -> Stocare variabile
/***********************************************************************/
#pragma once
#define SCOPE_MAX_DEPTH 256
// INCLUDES
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*****************************************
            VARIABLE RECORD STRUCT
*****************************************/

enum varType
{
    t_integer = 0,
    t_double,
    t_float,
    t_void
};

char *varTypeName[] = {"Int", "Double", "Float", "Void"};

enum programState
{
    parsing,
    executing
};

struct varRecord
{
    char *name;
    enum varType type;
    double value;
    struct varRecord *next;
};

typedef struct varRecord varRecord;

/*****************************************
            GLOBAL VARIABLES
*****************************************/

enum programState currentState = parsing; // Folosit pentru a stabili daca programul este in modul de parsare sau de executare

varRecord *(varScope[SCOPE_MAX_DEPTH]) = {NULL};
int scopeLevel = -1; // Scope level incepe la -1 pentru ca functiile fac IncreaseScope, ca si main

/*****************************************
                FUNCTIONS
*****************************************/

int increaseScope()
{
    if (scopeLevel >= SCOPE_MAX_DEPTH)
    {
        printf("ERROR: SCOPE LEVEL REACHED SUPERIOR LIMIT\n");
        return scopeLevel;
    }
    return ++scopeLevel;
}

int decreaseScope()
{
    if (scopeLevel != 0 || currentState == parsing)
        varScope[scopeLevel] = NULL;
    if (scopeLevel < 0)
    {
        printf("FATAL ERROR: SCOPE LEVEL IS BELOW 0\n");
        exit(-1);
    }
    return --scopeLevel;
}

varRecord *getVar(char *varName)
{
    varRecord *ptr;
    int scopeLevelCopy = scopeLevel;
    while (scopeLevelCopy >= 0)
    {
        for (ptr = varScope[scopeLevelCopy]; ptr != NULL; ptr = ptr->next)
            if (strcmp(ptr->name, varName) == 0)
            {
                if (ptr->type == t_integer)
                    ptr->value = (int)ptr->value;
                else if (ptr->type == t_float)
                    ptr->value = (float)ptr->value;
                return ptr;
            }
        scopeLevelCopy--;
    }
    return NULL;
}

varRecord *addVar(char *varName, enum varType type)
{
    if (getVar(varName) != (varRecord *)NULL)
        return NULL;
    varRecord *ptr = (varRecord *)malloc(sizeof(varRecord));
    ptr->name = (char *)calloc(strlen(varName) + 1, sizeof(char));
    strcpy(ptr->name, varName);
    ptr->value = 0;
    ptr->type = type;
    ptr->next = varScope[scopeLevel];
    varScope[scopeLevel] = ptr;
    if (ptr->type == t_integer)
        ptr->value = (int)ptr->value;
    return ptr;
}

void printAllVars()
{
    printf("\n***********************************\n");
    printf("\tPrinting variables\n");
    printf("***********************************\n\n");
    scopeLevel++; // scopelevel-ul pentru main este 0
    for (varRecord *ptr = varScope[scopeLevel]; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->type == t_integer)
        {
            printf("%s = %d;\n", ptr->name, (int)ptr->value);
        }
        else
        {
            printf("%s = %lg;\n", ptr->name, ptr->value);
        }
    }
}