/******************************************************************************
* fileName    : 04shell.c 
* author      : 114233763@qq.com
* date        : 2020-10-11 11:05:06
* description : 希尔排序
***************************************************************************** */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 10;
    int r[] = {45, 38, 63, 85, 71, 17, 28, 45, 6, 90};
    int d, i, j, k, x;
    d = 10 / 2;
    while (d >= 1)
    {
        for (i = 0; i < 10; i++)
        {
            x = r[i];
            j = i - d;
            while (j >= 0 && x < r[j])
            {
                r[j + d] = r[j];
                j = j - d;
            }
            r[j + d] = x;
        }
        d = d / 2;
    }

    for (k = 0; k < n; k++)
    {
        printf("%d,", r[k]);
    }

    return 0;
}