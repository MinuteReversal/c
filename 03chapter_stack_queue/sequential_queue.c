#include <stdio.h>
#include <malloc.h>
#define MAX_LEN 10

typedef struct _SeQueue
{
    int elements[MAX_LEN];
    int front, rear;
} SeQueue, *PSeQueue;

PSeQueue init()
{
    PSeQueue queue = (PSeQueue)malloc(sizeof(SeQueue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(PSeQueue queue)
{
    return queue->front == queue->rear;
}

int getFront(PSeQueue queue, int *value)
{
    if (isEmpty(queue))
    {
        return 0;
    }
    *value = queue->elements[queue->front + 1];
    return 1;
}

int enqueue(PSeQueue queue, int value)
{
    if (queue->rear == MAX_LEN - 1)
        return 0;

    queue->rear++;
    queue->elements[queue->rear] = value;
    return 1;
}

int dequeue(PSeQueue queue, int *value)
{
    if (isEmpty(queue))
    {
        return 0;
    }
    queue->front++;
    *value = queue->elements[queue->front];
    return 1;
}

void printQueue(PSeQueue queue)
{
    if (isEmpty(queue))
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
    PSeQueue queue = init();
    printf("enqueue:");
    for (size_t i = 0; i < 5; i++)
    {
        enqueue(queue, i);
    }

    printQueue(queue);

    printf("dequeue:");
    for (size_t i = 0; i < 5; i++)
    {
        int value;
        dequeue(queue, &value);
        printf("%d,", value);
    }
    printf("\n");

    printQueue(queue);

    return 0;
}