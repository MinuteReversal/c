/******************************************************************************
* fileName    : log2n.c 
* author      : 114233763@qq.com
* date        : 2020-10-11 21:59:28
* description : O(log2n)
 y=x^n
 x=logyn
***************************************************************************** */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 2048;                     //O(n)
    for (size_t i = 1; i < n; i *= 2) //O(log2n)
    {
        printf("%d,", i); //O(log2n)
    }

    return 0;
}