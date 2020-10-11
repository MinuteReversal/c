/******************************************************************************
* fileName    : n2.c 
* author      : 114233763@qq.com
* date        : 2020-10-11 21:41:51
* description : 时间复杂度O(n^2)
***************************************************************************** */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 10;                    //O(1)
    for (size_t i = 1; i < n; i++) //O(n)
    {
        for (size_t j = 1; j < n; j++) //O(n^2)
        {
            printf("%dx%d=%d ", j, i, j * i); //O(n^2)
        }
        printf("\n"); //O(n)
    }

    return 0;
}