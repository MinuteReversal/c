/******************************************************************************
* fileName    : stack_link.c 
* author      : 114233763@qq.com
* date        : 2020-09-08 21:45:55
* description : 栈的链式存储
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>

/**
 * 栈节点
 */
typedef struct _StackNode
{
    int value;               //值
    struct _StackNode *next; //嵌套
} StackNode, *PStackNode;

/**
 * 创建一个节点
 * @param value 值
 * @return 节点
 */
PStackNode create(int value)
{
    PStackNode node = (PStackNode)malloc(sizeof(StackNode));
    node->value = value;
    node->next = NULL;
    return node;
}

/**
 * 入栈
 * @param stack 栈
 * @return 栈
 */
PStackNode pushStack(PStackNode stack, int value)
{
    PStackNode node = create(value);
    if (stack)
    {
        node->next = stack;
    }
    return node;
}

/**
 * 出栈
 * @param stack 栈
 * @param value 出值
 * 
 */
PStackNode popStack(PStackNode stack, int *value)
{
    if (stack != NULL)
    {
        PStackNode next = stack->next;
        *value = stack->value;
        free(stack);
        return next;
    }
    return stack;
}
/**
 * 栈空
 * @param stack 栈
 * @return 0 未空 1 已空 
 */
int isEmpty(PStackNode stack)
{
    return stack == NULL;
}

int main(int argc, char const *argv[])
{
    PStackNode stack = NULL; //栈
    for (size_t i = 0; i < 10; i++)
    {
        printf("push:%d\n", i);
        stack = pushStack(stack, i);
    }

    int value;
    while (!isEmpty(stack))
    {
        stack = popStack(stack, &value);
        printf("pop:%d\n", value);
    }

    return 0;
}