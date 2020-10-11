/*! *****************************************************************************
fileName    : circular_queue.h 
author      : 114233763@qq.com
date        : 2020-10-11 22:40:05
version     : v1
description : 循环队列定义
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>
#define Q_MAX_LEN 10

/**
 * 循环队列定义
 */
typedef struct _Queue
{
    int elements[Q_MAX_LEN]; //数组
    int front, rear;         //队头，队尾下标
} Queue, *PQueue;

/**
 * 创建循环队列
 */
PQueue createQueue()
{
    PQueue queue = (PQueue)malloc(sizeof(Queue)); //实例化队列
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

int isFullQueue(PQueue queue)
{
    return (queue->rear + 1) % Q_MAX_LEN == queue->front;
}

int isEmptyQueue(PQueue queue)
{
    return queue->front == queue->rear;
}

int pushQueue(PQueue queue, int value)
{
    if (isFullQueue(queue))
        return 0;

    queue->rear = (queue->rear + 1) % Q_MAX_LEN;
    queue->elements[queue->rear] = value;
    return 1;
}

void printQueue(PQueue queue)
{
    int i;
    if (!isEmptyQueue(queue))
    {
        printf("print queue\n");
        i = queue->front;
        do
        {
            i = (i + 1) % Q_MAX_LEN;
            printf("%d,", queue->elements[i]);
        } while (i != queue->rear);
        printf("\n");
    }
    else
    {
        printf("The queue is empty");
    }
}

int popQueue(PQueue queue, int *value)
{
    if (isEmptyQueue(queue))
        return 0;
    else
    {
        queue->front = (queue->front + 1) % Q_MAX_LEN;
        *value = queue->elements[queue->front];
        return 1;
    }
}
