#include <stdio.h>
#include "sequence_queue.h"

int main(int argc, char const *argv[])
{
    PQueue queue = createQueue(); //创建队列
    printf("enqueue:");
    for (size_t i = 0; i < 5; i++)
    {
        pushQueue(queue, i); //入队
    }

    printQueue(queue); //打印队列里的内容

    printf("dequeue:");
    for (size_t i = 0; i < 5; i++)
    {
        int value;
        popQueue(queue, &value); //出队
        printf("%d,", value);    //打印
    }
    printf("\n");

    printQueue(queue); //打印

    return 0;
}