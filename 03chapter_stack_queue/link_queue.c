/******************************************************************************
* fileName    : link_queue.c 
* author      : 114233763@qq.com
* date        : 2020-10-11 22:34:48
* description : 链队调用
***************************************************************************** */
#include <stdio.h>
#include "link_queue.h"

int main(int argc, char const *argv[])
{
    PQueueNode front;
    PQueueNode rear;
    initQueue(&front, &rear); //初始化队
    for (size_t i = 0; i < 5; i++)
    {
        pushQueue(&rear, i); //入队
    }

    printQueue(front); //打印队情况

    for (size_t i = 0; i < 5; i++)
    {
        int value;
        popQueue(&front, &rear, &value); //出队
        printf("%d\n", value);           //打印
    }

    return 0;
}