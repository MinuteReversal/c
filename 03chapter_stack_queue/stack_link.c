/******************************************************************************
* fileName    : stack_link.c 
* author      : 114233763@qq.com
* date        : 2020-09-08 21:45:55
* description : 栈的链式存储
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>

typedef struct _StackNode
{
    int value;
    struct _StackNode *next;
} StackNode, *PStackNode;

PStackNode create(int value, PStackNode next)
{
    PStackNode node = (PStackNode)malloc(sizeof(StackNode));
    node->next = next;
    node->value = value;
    return node;
}

PStackNode push(PStackNode stack, int value)
{
    PStackNode node = create(value, stack);
    return node;
}

PStackNode pop(PStackNode stack, int *value)
{
    if (stack->next != NULL)
    {
        PStackNode next = stack->next;
        *value = stack->value;
        free(stack);
        return next;
    }
    return stack;
}

int isEmpty(PStackNode stack)
{
    return stack->next == NULL;
}

int main(int argc, char const *argv[])
{
    PStackNode stack = create(-1, NULL); //栈顶
    for (size_t i = 0; i < 10; i++)
    {
        printf("push:%d\n", i);
        stack = push(stack, i);
    }

    while (!isEmpty(stack))
    {
        int value;
        stack = pop(stack, &value);
        printf("pop:%d\n", value);
    }

    return 0;
}