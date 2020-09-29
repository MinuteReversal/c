/******************************************************************************
* fileName    : void_pointer.c 
* author      : 114233763@qq.com
* date        : 2020-09-29 09:47:50
* description : https://stackoverflow.com/questions/31260696/void-star-and-in-c
A void pointer(void* ) is a pointer that has no associated data type with it.
A void pointer can hold address of any type and can be typcasted to any type.
***************************************************************************** */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("%d\n", 0 == (void *)0);

    int a = 10;
    char b = 'x';
    
    void *unused = &a;
    unused = &b;

    return 0;
}