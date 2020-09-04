#include <stdio.h>
#include <malloc.h>

typedef struct _Node
{
    int value;
    struct _Node *next;
} Node, *PNode;

/**
 * 初始化
 */
void init(PNode *head, int length)
{
    PNode nextNode = NULL;
    for (int i = length; i > 0; i--)
    {
        PNode pNode = (PNode)malloc(sizeof(Node));
        pNode->value = i;
        pNode->next = nextNode;
        nextNode = pNode;
    }
    *head = nextNode;
}

/**
 * 向最最添加一个元素
 */
PNode append(PNode node, int value)
{
    PNode nextNode = (PNode)malloc(sizeof(Node));
    nextNode->value = value;
    nextNode->next = NULL;
    node->next = nextNode;
    return nextNode;
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

void printLinkedList(PNode head)
{
    for (PNode node = head; node != NULL; node = node->next)
    {
        printf("%d,", node->value);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    PNode head = NULL;
    PNode end = NULL;

    init(&head, 10);
    printf("#%p\n", head);
    printLinkedList(head);
    end = getEnd(head);
    append(end, 11);
    printLinkedList(head);
    clear(head);

    return 0;
}