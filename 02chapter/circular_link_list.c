#include <stdio.h>
#include <malloc.h>

/*
* 定义节点类型
*/
typedef struct _Node
{
    int value;
    struct _Node *next;
} Node, *PNode;

/**
 * 向后添加一个元素
 */
PNode add(PNode node, int value)
{
    PNode nextNode = (PNode)malloc(sizeof(Node));
    nextNode->value = value;
    nextNode->next = NULL;
    if (node)
    {
        if (node->next)
        {
            nextNode->next = node->next;
        }

        node->next = nextNode;
    }
    return nextNode;
}

/*
* 初始化
*/
PNode init(int length)
{
    PNode head = add(NULL, 0);
    PNode node = head;
    for (int i = 1; i < length; i++)
    {
        node = add(node, i);
    }
    return head;
}

/**
 * 获取最后一个节点
 */
PNode getEnd(PNode head)
{
    PNode node = head;
    while (node->next)
    {
        node = node->next;
    }
    return node;
}

/**
 * 通过值查找节点
 */
PNode findByValue(PNode head, int value)
{
    for (PNode node = head; node != NULL; node = node->next)
    {
        if (value == node->value)
        {
            return node;
        }
    }
    return NULL;
}

/**
 * 通过索引查找
 */
PNode findByIndex(PNode head, int index)
{
    PNode node = head;
    for (int i = 0; node; i++, node = node->next)
    {
        if (index == i)
        {
            return node;
        }
    }

    return NULL;
}

/**
 * 清除所有节点
 */
void clear(PNode head)
{
    PNode node;
    while (node)
    {
        PNode next = node->next;
        free(node);
        node = next;
    }
}

/**
 * 删除指定值的节点
 */
void removeByValue(PNode head, int value)
{
    for (PNode node = head; node; node = node->next)
    {
        PNode nextNode = node->next;
        if (nextNode->value == value)
        {
            node->next = nextNode->next;
            free(nextNode);
            break;
        }
    }
}

void printLinkList(PNode head)
{
    for (PNode node = head; node != NULL; node = node->next)
    {
        printf("%d,", node->value);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    PNode list = init(10);
    printf("#%p\n", list);
    printLinkList(list);

    PNode node3 = findByIndex(list, 2);
    add(node3, 888);
    printLinkList(list);

    removeByValue(list, 8);
    printLinkList(list);

    clear(list);

    return 0;
}