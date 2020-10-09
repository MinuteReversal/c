/******************************************************************************
* fileName    : hash_line_search.c 
* author      : 114233763@qq.com
* date        : 2020-10-09 10:10:30
* description : 线性探查法-平方探测
***************************************************************************** */
#include <stdio.h>
#include <math.h>
#include "../02chapter_list/sequence_list.h"

#define M 13

int hash1(int value)
{
    return value % M;
}

/**
 * (1,m-1)之间的素数
 */
int hash2(int key)
{
    const int primes[] = {
        2,
        3,
        5,
        7,
        11,
        13,
        17,
        19,
        23,
        29,
        31,
        37,
        41,
        43,
        47,
        53,
        59,
        61,
        67,
        71,
        73,
        79,
        83,
        89,
        97,
    };
    const int length = sizeof(primes) / sizeof(int);
    for (size_t i = length; i > 0; i--)
    {
        if (key > primes[i])
        {
            return primes[i];
        }
    }

    return -1;
}

int search(int key)
{
    int index = hash1(key);
    if (index > 0)
    {
        int di = index;
        di = (index + hash2(key)) % M;
        index = di;
    }
    return index;
}

void save(int value, int array[])
{
    int index = search(value);
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