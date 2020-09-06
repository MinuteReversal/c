#include <stdio.h>
#include <malloc.h>

typedef struct _Matrix
{
    int row, column;
    int *table;
} Matrix, *PMatrix;
/**
* 初始化矩阵
* @param row 行总数
* @param column 列总数
* @return 矩阵
*/
int *init(int rows, int columns)
{
    const int intSize = sizeof(int);
    int **a = (int **)malloc(sizeof(int *) * rows);
    int count = 0;
    for (size_t i = 0; i < rows; i++)
    {
        a[i] = (int *)malloc(intSize * columns);
        for (size_t j = 0; j < columns; j++)
        {
            *(a[i] + j) = count++;
        }
    }

    return *a;
}

void printMatrix(int *a, int rows, int columns)
{
    int intSize = sizeof(int);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("%d,", *(a + i * intSize + j));
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int a[3][4] = {
        {1, 3, 5, 7},
        {9, 11, 13, 15},
        {17, 19, 21, 23},
    };
    printMatrix(*a, 3, 4);
    printMatrix(init(5, 5), 5, 5);
    return 0;
}