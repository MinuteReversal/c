#include <stdio.h>
#include <malloc.h>

int **create(int size)
{
    int **a = malloc(size * sizeof(int *));
    int c = 0;
    for (size_t i = 0; i < size; i++)
    {
        a[i] = malloc(size * sizeof(int));
        for (size_t j = 0; j < size; j++)
        {
            a[i][j] = i * size + j;
        }
    }

    return a;
}

void printArray(int **array, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            printf("%d,", array[i][j]);
        }
        printf("\n");
    }
}

void disposeArray(int **array, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        free(array[i]);
    }
    free(array);
}

int main(int argc, char const *argv[])
{
    int **m = create(3);
    printArray(m, 3);
    disposeArray(m, 3);

    int m2[2][2] = {{0, 1}, {2, 3}};
    return 0;
}