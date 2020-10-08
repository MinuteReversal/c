/******************************************************************************
* fileName    : hash_remainder.c 
* author      : 114233763@qq.com
* date        : 2020-10-08 11:18:00
* description : 余数法
***************************************************************************** */
#include <stdio.h>

int hash(int key)
{
    return key % 13;
}

void save(int value, int array[])
{
    array[hash(value)] = value;
}

int main(int argc, char const *argv[])
{
    int a[] = {25, 74, 36, 40, 82, 65, 57};
    int list[13];

    for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        save(a[i], list);
    }

    return 0;
}