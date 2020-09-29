#include <stdio.h>
#include <malloc.h>
#ifndef Q_MAX_LEN
#define Q_MAX_LEN 10
#endif
typedef struct _Queue
{
    int elements[Q_MAX_LEN];
    int front, rear;
} Queue, *PQueue;

PQueue createQueue()
{
    PQueue queue = (PQueue)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmptyQueue(PQueue queue)
{
    return queue->front == queue->rear;
}

int getFront(PQueue queue, int *value)
{
    if (isEmptyQueue(queue))
    {
        return 0;
    }
    *value = queue->elements[queue->front + 1];
    return 1;
}

int pushQueue(PQueue queue, int value)
{
    if (queue->rear == Q_MAX_LEN - 1)
        return 0;

    queue->rear++;
    queue->elements[queue->rear] = value;
    return 1;
}

int popQueue(PQueue queue, int *value)
{
    if (isEmptyQueue(queue))
    {
        return 0;
    }
    queue->front++;
    *value = queue->elements[queue->front];
    return 1;
}

void printQueue(PQueue queue)
{
    if (isEmptyQueue(queue))
    {
        printf("The queue is emmpty!");
    }
    else
    {
        for (size_t i = queue->front + 1; i <= queue->rear; i++)
        {
            printf("%d,", queue->elements[i]);
        }
    }
    printf("\n");
}