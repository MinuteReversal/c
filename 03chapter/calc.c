/******************************************************************************
* fileName    : calc.c 
* author      : 114233763@qq.com
* date        : 2020-09-09 13:24:58
* description : 
 \ p2
P1\   |+|-|*|/|(|)|@|
+      > > < < < > > 
-      > > < < < > >
*      > > > > < > >
/      > > > > < > >
(      < < < < < =  
)      > > > >   > >
@      < < < < <   =
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>

typedef struct _StackNode
{
    int value;
    struct _StackNode *next;
} StackNode, *PStackNode;

/**
* 创建节点
* @param value 值
* @param next 下一个节点地址
* @return 创建的节点
*/
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
    char input[] = "6-8/4+3*5@";
    return 0;
}