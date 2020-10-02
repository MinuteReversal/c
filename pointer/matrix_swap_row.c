#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 2

void printMatrix(int *matrix[MAX_SIZE], int size)
{
    for (size_t j = 0; j < size; j++)
    {
        for (size_t i = 0; i < size; i++)
        {
            printf("%d,", *(matrix[j] + i));
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int m[MAX_SIZE][MAX_SIZE] = {{1, 2}, {3, 4}};

    int **pmatrix = (int **)malloc(MAX_SIZE * sizeof(int *));
    pmatrix[0] = m[0];
    pmatrix[1] = m[1];

    int *temp = pmatrix[0];
    pmatrix[0] = pmatrix[1];
    pmatrix[1] = temp;
    printMatrix(pmatrix, MAX_SIZE);

    return 0;
}