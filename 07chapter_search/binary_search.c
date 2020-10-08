#include <stdio.h>
#include <malloc.h>
#define MAX_ITEM 10

typedef struct _ElementAge
{
    int key;
} Element, *PElementAge;

int binarySsearch(Element list[], int length, int key)
{

    int low = 0, high = length, middle;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (key == list[middle].key)
        {
            return middle;
        }
        else if (key > list[middle].key)
        {
            low = middle + 1;
        }
        else
        {
            high = middle - 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    Element list[MAX_ITEM] = {0, 3, 4, 5, 7, 8, 10};

    int key = 5;
    int index = binarySsearch(list, 7, key);

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