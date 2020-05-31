//
// Created by Kate on 28.04.2020.
//
#include <cstdio>

#include "helpers.h"
int PositiveInteger(char* text)
{
    int res = 0;
    int error = 0;
    do {
        printf("%s", text);
        error = scanf("%d", &res);
        if (error != 1){
            printf("Wrong value! ");
        }
        fflush(stdin);
    } while(error != 1 || res <= 0);

    return res;
}
