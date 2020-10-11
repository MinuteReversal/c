/******************************************************************************
* fileName    : factorial.c 
* author      : 114233763@qq.com
* date        : 2020-10-11 22:18:29
* description : 
***************************************************************************** */
#include <stdio.h>

int factorial(int n)
{
    if (n > 1)
    {
        return n * factorial(n - 1);
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int n = 4;
    printf("%d!=%d\n", n, factorial(n));
    return 0;
}