/******************************************************************************
* fileName    : stack_sequence.c 
* author      : 114233763@qq.com
* date        : 2020-09-08 21:27:38
* description : 顺序栈
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>
#define STACK_MAX_LEN 10

typedef struct _Stack
{
    int elements[STACK_MAX_LEN];
    int top;
} Stack, *PStack;

/**
* 创建栈
* @return 栈 
*/
PStack createStack()
{
    PStack stack = (PStack)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

/**
* 获得栈顶的值
* @param stack 栈 
* @param value  out 值
* @return 0 异常 1 正常
*/
int getStackTop(PStack stack, int *value)
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
int pushStack(PStack stack, int value)
{
    if (stack->top == STACK_MAX_LEN - 1)
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
int popStack(PStack stack, int *value)
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
int isEmptyStack(PStack stack)
{
    return stack->top == -1;
}

/**
 * 满栈
 * @param stack 栈
 * @return 0 未满 1 已满
 */
int isFullStack(PStack stack)
{
    return stack->top == STACK_MAX_LEN - 1;
}