#pragma once
#include <stdio.h>

void handleBackSlashForBuffer(char c)
{
    switch (c)
    {
    case 'n':
        printf("\n");
        break;
    case 't':
        printf("\t");
        break;
    default:
        break;
    }
    return;
}