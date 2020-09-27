#include <stdio.h>
#include <malloc.h>
#define MATRIX_LEN 10
#ifndef INPUT_MATRIX_LEN
#define INPUT_MATRIX_LEN MATRIX_LEN
#endif
typedef struct _Matrix
{
    int rows, columns;
    int *table;
} Matrix, *PMatrix;

/**
* 初始化矩阵
* @param row 行总数
* @param column 列总数
* @return 矩阵
*/
PMatrix initMatix(int rows, int columns)
{
    const size_t intSize = sizeof(int);
    const size_t cells = rows * columns;
    PMatrix matrix = (PMatrix)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->table = (int *)malloc(intSize * cells);

    for (size_t i = 0; i < cells; i++)
    {
        matrix->table[i] = i + 1;
    }

    return matrix;
}

void printMatrix(PMatrix matrix)
{
    for (size_t i = 0; i < matrix->rows; i++)
    {
        for (size_t j = 0; j < matrix->columns; j++)
        {
            printf("%5d,", *(matrix->table + i * matrix->columns + j));
        }
        printf("\n");
    }
}

int **create(int array[INPUT_MATRIX_LEN][INPUT_MATRIX_LEN], int size)
{
    int **a = malloc(MATRIX_LEN * sizeof(int *));
    for (size_t i = 0; i < MATRIX_LEN; i++)
    {
        a[i] = malloc(MATRIX_LEN * sizeof(int));
        for (size_t j = 0; j < MATRIX_LEN; j++)
        {
            a[i][j] = (i < size && j < size) ? array[i][j] : 0;
        }
    }
    return a;
}

void printMatrixArray(int **array)
{
    for (size_t i = 0; i < MATRIX_LEN; i++)
    {
        for (size_t j = 0; j < MATRIX_LEN; j++)
        {
            printf("%d,", array[i][j]);
        }
        printf("\n");
    }
}

/**
* 释放矩阵
* @param matrix 矩阵 
* @return 无
*/
void disposeMatrix(PMatrix matrix)
{
    free(matrix->table);
    free(matrix);
}

void disposeMatrixArray(int **array)
{
    for (size_t i = 0; i < MATRIX_LEN; i++)
    {
        free(array[i]);
    }
    free(array);
}