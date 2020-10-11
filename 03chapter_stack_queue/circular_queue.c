/******************************************************************************
* fileName    : circular_queue.c 
* author      : 114233763@qq.com
* date        : 2020-10-11 22:16:56
* description : 循环队列
***************************************************************************** */
#include <stdio.h>
#include "circular_queue.h"

int main(int argc, char const *argv[])
{
    PQueue queue = createQueue(); //初始化循环队列
    for (size_t i = 0; i < 5; i++)
    {
        pushQueue(queue, i);
    }
    printQueue(queue);
    printf("pop queue\n");
    for (size_t i = 0; i < 5; i++)
    {
        int value;
        popQueue(queue, &value);
        printf("%d,", value);
    }
    printf("\n");
    for (size_t i = 0; i < 10; i++)
    {
        pushQueue(queue, i);
    }
    return 0;
}