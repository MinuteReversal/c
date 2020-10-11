/******************************************************************************
* fileName    : n3.c 
* author      : 114233763@qq.com
* date        : 2020-10-11 21:42:42
* description : 时间复杂度O(n^3)
***************************************************************************** */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 10;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            for (size_t k = 0; k < n; k++)
            {
                printf("%d%d%d,", i, j, k);
            }
        }
    }
    printf("\n");

    return 0;
}