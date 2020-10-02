
/******************************************************************************
* fileName    : adjacency_list.c 
* author      : 114233763@qq.com
* date        : 2020-09-24 21:31:55
* description : 邻接表深度遍历
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>
#include "../03chapter_stack_queue/circular_queue.h"
#define MAX_LEN 4

/** 表节点*/
typedef struct _Node
{
    int vertex;
    struct _Node *next;
} Node, *PNode;

/** 表头*/
typedef struct _HeadNode
{
    int data;
    Node *firstEdge;
} HeadNode, *PHeadNode;

//创建表头节点
PHeadNode createHead(int vertex)
{
    PHeadNode head = (PHeadNode)malloc(sizeof(HeadNode));
    head->firstEdge = NULL;
    head->data = 0; //没有访问过
    return head;
}

//创建节点
PNode createNode(int vertex)
{
    PNode node = (PNode)malloc(sizeof(Node));
    node->vertex = vertex;
    node->next = NULL;
    return node;
}

//追加节点
PNode appendNode(PNode priorNode, int vertex)
{
    PNode node = createNode(vertex);
    priorNode->next = node;
    return node;
}

//向表头追加节点
PNode appendHead(PHeadNode headNode, int vertex)
{
    return headNode->firstEdge = createNode(vertex);
}

//创建邻接表行
PHeadNode createRow(int vertex[], int length)
{
    PHeadNode head;
    PNode node;
    for (size_t i = 0; i < length; i++)
    {
        if (i == 0)
        {
            //头节点
            head = createHead(vertex[i]);
        }
        else if (i == 1)
        {
            //第一个边节点
            node = createNode(vertex[i]);
            head->firstEdge = node;
        }
        else
        {
            node = appendNode(node, vertex[i]);
        }
    }
    return head;
}

/**
 * 打印邻接表
 * 
 */
void printList(PHeadNode table[], int length)
{
    for (size_t i = 0; i < length; i++)
    {
        PHeadNode head = table[i];
        printf(" %d==>", i);

        PNode node = head->firstEdge;
        while (node != NULL)
        {
            printf("---->%d", node->vertex);
            node = node->next;
        }
        printf("\n");
    }
}

/**
 * 深度优先遍历
 * @param list 邻接表
 * @param v 顶点
 * @return 无
 */
void depthFirst(PHeadNode list[], int v)
{
    PHeadNode head = list[v];
    PNode currentNode = head->firstEdge;
    printf("%d,", v);  //打印顶点号
    head->data = 1; //标记为访问过此顶
    while (currentNode != NULL)
    {
        int vertex = currentNode->vertex;
        if (list[vertex]->data == 0)
        {
            depthFirst(list, vertex);
        }
        currentNode = currentNode->next;
    }
}

/**
 * 广度优先遍历
 * @param list 邻接表
 * @param v 顶点号
 * @return 无
 */
void breadthFirst(PHeadNode list[], int v)
{
    PQueue queue = createQueue();
    PNode p = list[v]->firstEdge; //当前节点p
    printf("%d,", v);
    list[v]->data = 1;
    pushQueue(queue, v);
    while (!isEmptyQueue(queue))
    {
        popQueue(queue, &v);
        p = list[v]->firstEdge;
        while (p)
        {
            if (!list[p->vertex]->data)
            {
                printf("%d,", p->vertex);
                list[p->vertex]->data = 1;
                pushQueue(queue, p->vertex);
            }
            p = p->next;
        }
    }
}

int main(int argc, char const *argv[])
{
    /**
     *         (0)
     *        /   \
     *       /     \
     *     (1)-----(2)
     *       \     /
     *        \   /
     *         (3)
     * 
     * 顶点 访问
     *  0 [0]->[1]->[2]
     *  1 [0]->[0]->[2]->[3]
     *  2 [0]->[0]->[1]->[3]
     *  3 [0]->[1]->[2]
     */
    PHeadNode list[MAX_LEN];
    list[0] = createRow((int[]){0, 1, 2}, 3);
    list[1] = createRow((int[]){1, 0, 2, 3}, 4);
    list[2] = createRow((int[]){2, 0, 1, 3}, 4);
    list[3] = createRow((int[]){3, 1, 2}, 3);

    printList(list, MAX_LEN);
    breadthFirst(list, 0);
    printf("\n");
    return 0;
}