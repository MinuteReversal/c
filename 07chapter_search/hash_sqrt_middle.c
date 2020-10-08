/******************************************************************************
* fileName    : hash_sqrt_middle.c 
* author      : 114233763@qq.com
* date        : 2020-10-08 10:18:40
* description : 平方取中 
***************************************************************************** */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int hash(int key)
{
    int result = pow(key, 2);
    char str[10];
    itoa(result, str, 10);
    char middle[] = {str[4], str[5], str[6], '\0'};
    return atoi(middle);
}

int main(int argc, char const *argv[])
{
    int r = hash(42016);
    return 0;
}