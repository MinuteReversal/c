/******************************************************************************
* fileName    : abc.c 
* author      : 114233763@qq.com
* date        : 2020-10-11 22:13:46
* description : 栈的应用，请在31行加断点F11步进
***************************************************************************** */
#include <stdio.h>

void fnC()
{
    printf("fnC start");
    printf("fnC end");
}

void fnB()
{
    printf("fnB start");
    fnC();
    printf("fnB end");
}

void fnA()
{
    printf("fnA start");
    fnB();
    printf("fnA end");
}

int main(int argc, char const *argv[])
{
    fnA();
    return 0;
}