#include <stdio.h>
#include <malloc.h>

typedef int *PArray;

int *createArray(int length)
{
    PArray array = (PArray)malloc(sizeof(int) * length);
    for (size_t i = 0; i < length; i++)
    {
        array[i] = i;
    }
    return array;
}

void printArray(int array[], int length)
{
    for (size_t i = 0; i < length; i++)
    {
        printf("%d,", array[i]);
    }
    printf("\n");
}

void disposeArray(int *array)
{
    free(array);
}

int main(int argc, char const *argv[])
{
    int length = 10;
    PArray array = createArray(length);
    printf("%d\n", array[1]);
    printArray(array, length);
    disposeArray(array);
    return 0;
}