#include <stdio.h>
#include "circular_queue.h"

int main(int argc, char const *argv[])
{
    PQueue queue = initQueue();
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
    return 0;
}