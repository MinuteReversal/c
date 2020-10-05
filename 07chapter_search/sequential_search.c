#include <stdio.h>
#include <malloc.h>
#define MAX_ITEM 10

typedef struct _Element
{
    int key;
} Element, *PElement;

int search(Element list[], int length, int key)
{
    for (size_t i = 0; i < length; i++)
    {
        if (list[i].key == key)
            return i;
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    Element list[MAX_ITEM] = {0, 7, 3, 5, 8, 10, 4};

    int key = 5;
    int index = search(list, 7, key);

    if (index > -1)
    {
        printf("%d的下标是%d\n", key, index);
    }
    else
    {
        printf("无此元素\n");
    }

    return 0;
}