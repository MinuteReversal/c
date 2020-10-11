/******************************************************************************
* fileName    : n.c 
* author      : 114233763@qq.com
* date        : 2020-10-11 21:41:31
* description : 时间复杂度O(n)
***************************************************************************** */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 5;                     //O(1)
    int a[5];                      //O(1)
    for (size_t i = 0; i < n; i++) //O(n)
    {
        a[i] = i; //O(n)
    }

    return 0;
}