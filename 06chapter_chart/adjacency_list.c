/******************************************************************************
* fileName    : adjacency_list.c 
* author      : 114233763@qq.com
* date        : 2020-09-24 21:31:55
* description : 邻接表
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>
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
    int vertex;
    Node *firstEdge;
} HeadNode, *PHeadNode;

//创建表头节点
PHeadNode createHead(int vertex)
{
    PHeadNode head = (PHeadNode)malloc(sizeof(HeadNode));
    head->vertex = vertex;
    head->firstEdge = NULL;
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
        printf(" %d==>", head->vertex);

        PNode node = head->firstEdge;
        while (node != NULL)
        {
            printf("---->%d", node->vertex);
            node = node->next;
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    /**
     * (v0)------(v2)
     *  | \      /
     *  |   \  /
     *  |    /\
     *  |  /    \
     * (v1)------(v3)
     * 
     * 0 [v0]->[1]->[2]->[3]
     * 1 [v1]->[0]->[2]->[3]
     * 2 [v2]->[0]->[1]
     * 3 [v3]->[0]->[1]
     */
    PHeadNode head[MAX_LEN];
    head[0] = createRow((int[]){0, 1, 2, 3}, 4);
    head[1] = createRow((int[]){1, 0, 2, 3}, 4);
    head[2] = createRow((int[]){2, 0, 1}, 3);
    head[3] = createRow((int[]){3, 0, 1}, 3);

    printList(head, MAX_LEN);
    return 0;
}