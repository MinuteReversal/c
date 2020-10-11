#include <stdio.h>
#include <malloc.h>

/*
* 定义节点类型
*/
typedef struct _Node
{
    //前驱
    struct _Node *prior;
    //值
    int value;
    //后继
    struct _Node *next;
} Node, *PNode;

/**
 * 向后添加一个元素
 */
PNode insertAfter(PNode priorNode, int value)
{
    PNode currentNode = (PNode)malloc(sizeof(Node)); //当前节点
    currentNode->value = value;
    currentNode->next = NULL;
    currentNode->prior = NULL;
    if (priorNode)
    {
        currentNode->prior = priorNode; //设置前驱

        if (priorNode->next)
        {
            currentNode->next = priorNode->next;
        }

        priorNode->next = currentNode; //设置后继
    }
    return currentNode;
}

/*
* 初始化
*/
PNode init(int length)
{
    PNode head = insertAfter(NULL, 0);
    PNode node = head;
    for (int i = 1; i < length; i++)
    {
        node = insertAfter(node, i);
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
    PNode node = head;
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

/**
 * 删除指定节点
 */
void removeNode(PNode node)
{
    PNode priorNode = node->prior;
    PNode nextNode = node->next;
    if (priorNode && nextNode)
    {
        priorNode->next = nextNode;
        nextNode->prior = priorNode;
    }
}

/**
 * 通过值删除
 */
void removeByValue(PNode head, int value)
{
    for (PNode node = head; node; node = node->next)
    {
        if (node->value == value)
        {
            removeNode(node);
            break;
        }
    }
}

/**
 * 打印单个节点
 */
void printNode(PNode node)
{
    printf("%d,", node->value);
}

void printLinkList(PNode head)
{
    for (PNode node = head; node != NULL; node = node->next)
    {
        printNode(node);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    PNode list = init(10);
    printf("#%p\n", list);
    printLinkList(list);

    PNode node3 = findByIndex(list, 2);
    insertAfter(node3, 888);
    printLinkList(list);

    removeByValue(list, 8);
    printLinkList(list);

    clear(list);

    return 0;
}