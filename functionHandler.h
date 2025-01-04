#pragma once
#define MAX_PARAMS 10
#include "VTR.h"
#include <string.h>
#include <stdlib.h>

struct functionRecord
{
    int functionIndex;
    char name[256];
    int nrParams;
    enum varType type;
    varRecord parameters[MAX_PARAMS];
    struct functionRecord *next;
};

typedef struct functionRecord functionRecord;

functionRecord *fctHead = (functionRecord *)NULL;

functionRecord *getFunction(char *name)
{
    for (functionRecord *ptr = fctHead; ptr != NULL; ptr = ptr->next)
    {
        if (strcmp(ptr->name, name) == 0)
            return ptr;
    }
    return NULL;
}

functionRecord *addFunction(char *name, int functionIndex)
{
    if (getFunction(name) != NULL)
        return NULL;
    functionRecord *ptr = (functionRecord *)malloc(sizeof(functionRecord));
    strcpy(ptr->name, name);
    ptr->functionIndex = functionIndex;
    ptr->next = fctHead;
    ptr->nrParams = 0;
    fctHead = ptr;
    return ptr;
}

void addParamsToFunction(char *name, char *paramName, enum varType paramType)
{
    functionRecord *ptr = getFunction(name);
    if (ptr == NULL)
        exit(-1);
    varRecord var;
    strcpy(var.name, paramName);
    var.type = paramType;
    var.next = NULL;
    var.value = 0;
    ptr->parameters[ptr->nrParams++] = var;
}