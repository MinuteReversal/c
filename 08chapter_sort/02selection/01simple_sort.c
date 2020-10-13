/******************************************************************************
* fileName    : simple.c 
* author      : 114233763@qq.com
* date        : 2020-10-11 11:10:48
* description : 简单排序
***************************************************************************** */
#include <stdio.h>
#define LENGTH 8

int main(int argc, char const *argv[])
{
    int temp, k;
    int r[LENGTH] = {45, 38, 63, 5, 71, 28, 45, 16};
    for (size_t i = 0; i < LENGTH; i++)
    {
        k = i;
        for (size_t j = i; j < LENGTH; j++)
        {
            if (r[k] > r[j])
            {
                k = j;
            }
        }
        if (i != k)
        {
            temp = r[i];
            r[i] = r[k];
            r[k] = temp;
        }
    }

    for (size_t i = 0; i < LENGTH; i++)
    {
        printf("%d,", r[i]);
    }

    return 0;
}