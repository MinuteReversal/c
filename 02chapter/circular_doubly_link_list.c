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
 * 向传入的节点后面添加一个元素
 * @param previous 前面一个元素
 * @param value 值
 * @return 创建的节点
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
    PNode head = insertAfter(NULL, 0); //生成头元素
    PNode end = head;
    //生成后面的元素
    for (int i = 1; i < length; i++)
    {
        end = insertAfter(end, i);
    }
    //让头尾相接
    end->next = head;
    return head;
}

/**
 * 获取最后一个节点
 */
PNode getEnd(PNode head)
{
    PNode node = head;
    while (node->next != head)
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
    for (PNode node = head; node->next != head; node = node->next)
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
    for (int i = 0; node->next != head; i++, node = node->next)
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
    for (PNode node = head; node->next != head;)
    {
        PNode next = node->next;
        node->next = next->next;
        free(next);
    }
}
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
 * 删除指定值的节点
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

void printLinkList(PNode head)
{
    for (PNode node = head; node->next != head; node = node->next)
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
    insertAfter(node3, 888);
    printLinkList(list);

    removeByValue(list, 8);
    printLinkList(list);

    clear(list);

    return 0;
}