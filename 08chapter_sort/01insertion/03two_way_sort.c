/******************************************************************************
* fileName    : 03two-way.c 
* author      : 114233763@qq.com
* date        : 2020-10-11 10:52:56
* description : 二路插入排序
***************************************************************************** */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i, j, first, final;
    int n = 8;
    int r[] = {42, 36, 56, 78, 67, 11, 27, 36};
    int d[n];
    d[0] = r[0];
    first = final = 0;
    for (i = 1; i < n; i++)
    {
        if (r[i] >= d[0])
        {
            for (j = final; r[i] < d[j]; j--)
            {
                d[j + 1] = d[j];
            }
            d[j + 1] = r[i];
            final++;
        }
        else
        {
            if (first == 0)
            {
                first = 7;
                d[first] = r[i];
            }
            else
            {
                for (j = first; r[i] > d[j] && j < n; j++)
                {
                    d[j - 1] = d[j];
                }
                d[j - 1] = r[i];
                first--;
            }
        }
    }
    if (first < final)
    {
        for (i = first; i <= final; i++)
        {
            printf("%d", d[i]);
        }
    }
    else
    {
        for (i = first; i < n; i++)
        {
            printf("%d,", d[i]);
        }
        for (i = 0; i <= final; i++)
        {
            printf("%d,", d[i]);
        }
    }
    printf("\n");
    return 0;
}