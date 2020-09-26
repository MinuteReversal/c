/******************************************************************************
* fileName    : stack_sequence.c 
* author      : 114233763@qq.com
* date        : 2020-09-08 21:27:38
* description : 顺序栈
***************************************************************************** */
#include <stdio.h>
#include "sequence_stack.h"

int main(int argc, char const *argv[])
{
    PStack stack = createStack();
    for (size_t i = 0; i < MAX_LEN; i++)
    {
        printf("push:%d\n", i);
        pushStack(stack, i);
    }

    while (!isEmptyStack(stack))
    {
        int value = 0;
        popStack(stack, &value);
        printf("pop:%d\n", value);
    }

    return 0;
}