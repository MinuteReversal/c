/******************************************************************************
* fileName    : adjacency_list.c 
* author      : 114233763@qq.com
* date        : 2020-09-24 21:31:55
* description : 邻接表
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>
#ifndef MAX_LEN
#define MAX_LEN 4
#endif

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
    head->data = 0;
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

void printList(PHeadNode list[], int length)
{
    for (size_t i = 0; i < length; i++)
    {
        PHeadNode head = list[i];
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