#include <stdio.h>
#include <malloc.h>

typedef struct _QueueNode
{
    int data;
    struct _QueueNode *next;
} QueueNode, *PQueueNode;

/**
* 创建一个节点
* @param rear 队尾
* @param data 值
* @return 新创建的节点
*/
PQueueNode createQueueNode(PQueueNode rear, int data)
{
    PQueueNode p = (PQueueNode)malloc(sizeof(QueueNode)); //新创建的节点
    p->data = data;
    p->next = NULL;

    if (rear)
    {
        rear->next = p;
    }
    return p;
}

/**
* 初始化
* @param front 队首
* @param rear 队尾
* @return 无
*/
void initQueue(PQueueNode *front, PQueueNode *rear)
{
    *front = createQueueNode(NULL, -1);
    *rear = *front;
}

/**
* 入队
* @param rear 队尾
* @param data 值
* @return 无
*/
void pushQueue(PQueueNode *rear, int data)
{
    *rear = createQueueNode(*rear, data);
}

void popQueue(PQueueNode *front, PQueueNode *rear, int *value)
{
    PQueueNode p = (*front)->next; //指向表头后面的一个元素
    if (*front != *rear)
    {
        (*front)->next = p->next;
        if (p->next == NULL)
            *rear = *front;
        *value = p->data;
        free(p);
    }
    else
    {
        printf("link queue is empty!");
    }
}

void printQueue(PQueueNode front)
{
    for (PQueueNode p = front->next; p; p = p->next)
    {
        printf("%d\n", p->data);
    }
}
