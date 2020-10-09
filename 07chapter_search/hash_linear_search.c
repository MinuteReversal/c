/******************************************************************************
* fileName    : hash_line_search.c 
* author      : 114233763@qq.com
* date        : 2020-10-09 10:10:30
* description : 线性探查法
***************************************************************************** */
#include <stdio.h>
#include "../02chapter_list/sequence_list.h"

#define M 13

int hash(int d, int array[])
{
    for (size_t i = 0; i < M; i++)
    {
        int index = (d + i) % M;
        int key = array[index];
        if (key == 0)
        {
            return index;
        }
    }
    return -1;
}

void save(int value, int array[])
{
    int index = hash(value, array);
    if (index > -1)
    {
        array[index] = value;
    }
}

void print(int array[], int length)
{
    for (size_t i = 0; i < length; i++)
    {
        printf("%d,", array[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int a[] = {25, 74, 36, 40, 82, 65, 57};
    int keys[M];
    initArrayByZero(keys, M);

    for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        save(a[i], keys);
    }
    print(keys, M);
    save(43, keys); //与82地址冲突
    print(keys, M);

    save(58, keys);
    print(keys, M);

    return 0;
}