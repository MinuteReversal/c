/******************************************************************************
* fileName    : struct.c 
* author      : 114233763@qq.com
* date        : 2020-09-03 14:46:18
* description : https://docs.microsoft.com/en-us/cpp/c-language/typedef-declarations?view=vs-2019
***************************************************************************** */
#include <stdio.h>
#include "struct.h"

int main(int argc, char const *argv[])
{
    Point point;
    PPoint pPoint = &point;
    pPoint->x = 10;
    pPoint->y = 20;

    printf("%d\n", pPoint->x + pPoint->y);
    return 0;
}