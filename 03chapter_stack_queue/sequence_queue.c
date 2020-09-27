#include <stdio.h>
#include <malloc.h>
#define Q_MAX_LEN 10

typedef struct _Queue
{
    int elements[Q_MAX_LEN];
    int front, rear;
} Queue, *PQueue;

PQueue initQueue()
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

int main(int argc, char const *argv[])
{
    PQueue queue = initQueue();
    printf("enqueue:");
    for (size_t i = 0; i < 5; i++)
    {
        pushQueue(queue, i);
    }

    printQueue(queue);

    printf("dequeue:");
    for (size_t i = 0; i < 5; i++)
    {
        int value;
        popQueue(queue, &value);
        printf("%d,", value);
    }
    printf("\n");

    printQueue(queue);

    return 0;
}