#include <stdio.h>
#include "sequence_queue.h"

int main(int argc, char const *argv[])
{
    PQueue queue = createQueue();
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