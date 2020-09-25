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
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

int isFull(PSeQueue queue)
{
    return (queue->rear + 1) % MAX_LEN == queue->front;
}

int isEmpty(PSeQueue queue)
{
    return queue->front == queue->rear;
}

int enqueue(PSeQueue queue, int value)
{
    if (isFull(queue))
        return 0;

    queue->rear = (queue->rear + 1) % MAX_LEN;
    queue->elements[queue->rear] = value;
    return 1;
}

void printQueue(PSeQueue queue)
{
    int i;
    if (!isEmpty(queue))
    {
        printf("print queue\n");
        i = queue->front;
        do
        {
            i = (i + 1) % MAX_LEN;
            printf("%d,", queue->elements[i]);
        } while (i != queue->rear);
        printf("\n");
    }
    else
    {
        printf("The queue is empty");
    }
}

int dequeue(PSeQueue queue, int *value)
{
    if (isEmpty(queue))
        return 0;
    else
    {
        queue->front = (queue->front + 1) % MAX_LEN;
        *value = queue->elements[queue->front];
        return 1;
    }
}

int main(int argc, char const *argv[])
{
    PSeQueue queue = init();
    for (size_t i = 0; i < 5; i++)
    {
        enqueue(queue, i);
    }
    printQueue(queue);
    printf("dequeue\n");
    for (size_t i = 0; i < 5; i++)
    {
        int value;
        dequeue(queue, &value);
        printf("%d,", value);
    }
    printf("\n");
    return 0;
}