#include <stdio.h>
#include <malloc.h>

/*
* 定义节点类型
*/
typedef struct _LinkNode
{
    int value;
    struct _LinkNode *next;
} LinkNode, *PLinkNode;

/**
 * 创建链表节点
 * @param value 值
 * @return 节点
 */
PLinkNode createLinkNode(int value)
{
    PLinkNode node = (PLinkNode)malloc(sizeof(LinkNode));
    node->value = value;
    node->next = NULL;
    return node;
}

/**
 * 向后添加一个元素
 * @param node 节点
 * @param value 值
 * @return 创建的节点
 */
PLinkNode insertAfter(PLinkNode node, int value)
{
    PLinkNode nextNode = createLinkNode(value);
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

/**
* 初始化
* 将链表的成员初始化为0,1,2,3....
* @param length 长度
* @return 链表头
*/
PLinkNode init(int length)
{
    PLinkNode head = insertAfter(NULL, 0);
    PLinkNode node = head;
    for (int i = 1; i < length; i++)
    {
        node = insertAfter(node, i);
    }
    return head;
}

/**
 * 获取最后一个节点
 * @param head 头节点
 * @return 最后一个节点
 */
PLinkNode getEnd(PLinkNode head)
{
    PLinkNode node = head;
    while (node->next)
    {
        node = node->next;
    }
    return node;
}

/**
 * 通过值查找节点
 */
PLinkNode findByValue(PLinkNode head, int value)
{
    for (PLinkNode node = head; node != NULL; node = node->next)
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
PLinkNode findByIndex(PLinkNode head, int index)
{
    PLinkNode node = head;
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
* 删除指定节点后的节点
* 
* @param head 列表 
* @param priorNode 指定的节点
* @return 无
*/
void removeAfter(PLinkNode head, PLinkNode priorNode)
{
    PLinkNode currentNode = priorNode->next;      //要删除的节点
    PLinkNode removeNodeNext = currentNode->next; //要删除的节点的下一个节点

    if (currentNode)
    {
        free(currentNode); //删除当前节点
    }
    if (removeNodeNext)
    {
        priorNode->next = removeNodeNext;
    }
}

/**
 * 清除所有节点
 */
void clear(PLinkNode head)
{
    PLinkNode node = head;
    while (node)
    {
        PLinkNode next = node->next;
        free(node);
        node = next;
    }
}

/**
 * 删除指定值的节点
 */
void removeByValue(PLinkNode head, int value)
{
    for (PLinkNode node = head; node; node = node->next)
    {
        PLinkNode nextNode = node->next;
        if (nextNode->value == value)
        {
            removeAfter(head, node);
            break;
        }
    }
}

/**
 *  打印单个节点
 * @param node 节点
 * @return 无
 */
void printNode(PLinkNode node)
{
    printf("%d,", *node);
}

/**
 * 打印链表
 * @param head 头节点
 */
void printLinkList(PLinkNode head)
{
    for (PLinkNode node = head; node != NULL; node = node->next)
    {
        printNode(node);
    }
    printf("\n");
}
