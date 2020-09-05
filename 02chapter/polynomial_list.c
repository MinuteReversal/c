/******************************************************************************
* fileName    : polynomial_list.c 
* author      : 114233763@qq.com
* date        : 2020-09-05 15:51:47
* description : polynomial list 一元多项式 3x + 5x^2 + 8x^3
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>

/*
* 定义节点类型
*/
typedef struct _Node
{
    int coef; //系数 coefficient
    int exp;  //指数 exponent
    struct _Node *next;
} Node, *PNode;

/**
 * 向后添加一个元素
 * @param node 指定的节点
 * @param coef 系数
 * @param exp  指数
 * @return 创建的节点
 */
PNode insertAfter(PNode node, int coef, int exp)
{
    PNode nextNode = (PNode)malloc(sizeof(Node));
    nextNode->coef = coef;
    nextNode->exp = exp;
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
PNode init(int *array, int length)
{
    PNode head = insertAfter(NULL, array[0], array[1]);
    PNode node = head;
    for (int i = 2; i < length; i += 2)
    {
        node = insertAfter(node, array[i], array[i + 1]);
    }
    return head;
}

/**
 * 获取最后一个节点
 */
PNode getEnd(PNode head, int *outLength)
{
    PNode node = head;
    int length = 1;
    while (node->next)
    {
        node = node->next;
        length++;
    }
    if (outLength)
    {
        *outLength = length;
    }
    return node;
}

/**
* 删除指定节点后的节点
* 
* @param head 列表 
* @param priorNode 指定的节点
* @return 无
*/
void removeAfter(PNode head, PNode priorNode)
{
    PNode currentNode = priorNode->next;      //要删除的节点
    PNode removeNodeNext = currentNode->next; //要删除的节点的下一个节点

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
 * 打印单个节点
 * @param node 节点
 * @return 无
 */
void printNode(PNode node)
{
    printf("%dx^%d,", node->coef, node->exp);
}

/**
 * 打印整个链表
 * @param head 链表
 * @return 无
 */
void printLinkList(PNode head)
{
    for (PNode node = head; node != NULL; node = node->next)
    {
        printNode(node);
    }
    printf("\n");
}

/**
 * 一元多项式加法运算
 * @param headA 表A
 * @param headB 表B
 * @return 结果表
 */
PNode add(PNode headA, PNode headB)
{
    PNode listR = insertAfter(NULL, 0, -1); //结果表头
    PNode nextR = listR;                    //下一个节点
    PNode nodeA = headA;                    //表A中的节点
    PNode nodeB = headB;                    //表B中的节点

    while (nodeA && nodeB)
    {
        //指数相同
        if (nodeA->exp == nodeB->exp)
        {
            int coef = nodeA->coef + nodeB->coef; //计算相加后的系数
            if (coef != 0)
            { //排除系数为0的节点
                nextR = insertAfter(nextR, coef, nodeA->exp);
            }
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        //指数小的nodeA
        else if (nodeA->exp < nodeB->exp)
        {
            nextR = insertAfter(nextR, nodeA->coef, nodeA->exp);
            nodeA = nodeA->next;
        }
        //指数小的nodeB
        else
        {
            nextR = insertAfter(nextR, nodeB->coef, nodeB->exp);
            nodeB = nodeB->next;
        }
    }

    nextR = listR->next;
    free(listR);

    return nextR;
}

int main(int argc, char const *argv[])
{
    int inputA[] = {1, 0, 2, 1, 4, 3};
    PNode listA = init(inputA, sizeof(inputA) / sizeof(int));

    int inputB[] = {2, 0, -2, 1, 3, 2};
    PNode listB = init(inputB, sizeof(inputB) / sizeof(int));

    //结果链表
    PNode listR = add(listA, listB);

    printLinkList(listA);
    printLinkList(listB);
    printLinkList(listR);

    clear(listA);
    clear(listB);
    clear(listR);
    return 0;
}