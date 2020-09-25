/******************************************************************************
* fileName    : stack_sequence.c 
* author      : 114233763@qq.com
* date        : 2020-09-08 21:27:38
* description : 顺序栈
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>
#define MAX_LEN 10

typedef struct _StackSq
{
    int elements[MAX_LEN];
    int top;
} StackSq, *PStackSq;

/**
* 创建栈
* @return 栈 
*/
PStackSq createStack()
{
    PStackSq stack = (PStackSq)malloc(sizeof(StackSq));
    stack->top = -1;
    return stack;
}

/**
* 获得栈顶的值
* @param stack 栈 
* @param value  out 值
* @return 0 异常 1 正常
*/
int getTop(PStackSq stack, int *value)
{
    if (stack->top = -1)
    {
        return 0;
    }
    *value = stack->elements[stack->top];
    return 1;
}

/**
* 进栈/压栈/
* @param stack 栈
* @param value 值
* @return 0 异常 1 正常
*/
int push(PStackSq stack, int value)
{
    if (stack->top == MAX_LEN - 1)
    {
        return 0;
    }
    stack->top++;
    stack->elements[stack->top] = value;
    return 1;
}

/**
* 出栈/弹栈
* @param stack 栈
* @param value out 值
* @return 01
*/
int pop(PStackSq stack, int *value)
{
    if (stack->top == -1)
    {
        return 0;
    }
    *value = stack->elements[stack->top];
    stack->top--;
    return 1;
}

/**
* 空栈
* @param stack 栈
* @return 0 非空 1 空 
*/
int isEmpty(PStackSq stack)
{
    return stack->top == -1;
}

int main(int argc, char const *argv[])
{
    PStackSq stack = createStack();
    for (size_t i = 0; i < MAX_LEN; i++)
    {
        printf("push:%d\n", i);
        push(stack, i);
    }

    while (!isEmpty(stack))
    {
        int value = 0;
        pop(stack, &value);
        printf("pop:%d\n", value);
    }

    return 0;
}