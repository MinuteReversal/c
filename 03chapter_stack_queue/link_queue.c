#include <stdio.h>
#include "link_queue.h"

int main(int argc, char const *argv[])
{
    PQueueNode front;
    PQueueNode rear;
    initQueue(&front, &rear);
    for (size_t i = 0; i < 5; i++)
    {
        pushQueue(&rear, i);
    }

    printQueue(front);

    for (size_t i = 0; i < 5; i++)
    {
        int value;
        popQueue(&front, &rear, &value);
        printf("%d\n", value);
    }

    return 0;
}