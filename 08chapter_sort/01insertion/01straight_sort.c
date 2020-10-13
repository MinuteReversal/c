/******************************************************************************
* fileName    : 01straight.c 
* author      : 114233763@qq.com
* date        : 2020-10-10 16:31:32
* description : 直接插入
***************************************************************************** */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 8;
    int temp = 0;
    int r[] = {0, 42, 36, 56, 78, 67, 11, 27, 36};
    int i, j;
    for (i = 1; i <= n; i++)
    {
        if (r[i] < r[i - 1])
        {
            r[0] = r[i];
            for (j = i - 1; r[0] < r[j]; j--)
            {
                r[j + 1] = r[j];
            }
            r[j + 1] = r[0];
        }
    }

    for (i = 1; i <= n; i++)
    {
        printf("%d,", r[i]);
    }

    return 0;
}