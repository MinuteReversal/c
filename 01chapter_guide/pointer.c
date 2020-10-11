/******************************************************************************
* fileName    : pointer.c 
* author      : 114233763@qq.com
* date        : 2020-10-11 21:48:49
* description : 指针一改全改
***************************************************************************** */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 123;   //创建一个变量
    int *pi1 = &i; //创建一个指针指向变量i
    int *pi2 = &i; //创建一个指针指向变量i
    int *pi3 = &i; //创建一个指针指向变量i

    *pi2 = 888; //修改指针指向的区域里装的内容

    printf("%d\n", i);
    printf("%d\n", *pi1);
    printf("%d\n", *pi2);
    printf("%d\n", *pi3);
    return 0;
}