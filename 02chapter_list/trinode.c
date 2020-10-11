/******************************************************************************
* fileName    : trinode.c 
* author      : 114233763@qq.com
* date        : 2020-09-06 15:57:01
* description : 稀疏矩阵--三元组
非零元素多于零元素
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>

typedef struct _TriNode
{
    //行号
    int row;
    //列号
    int column;
    //值
    int value;
} TriNode, *PTriNode;

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

    for (size_t row = 0; row < rows; row++)
    {
        for (size_t column = 0; column < columns; column++)
        {
            int *cell = &matrix->table[row * columns + column];
            if (column <= row)
            {
                *cell = row * columns + column + 1;
            }
            else
            {
                *cell = 0;
            }
        }
    }

    return matrix;
}

/**
 * 打印矩阵
 * @param matrix 矩阵
 * @return 无
 */
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

/**
* 保存下三角矩阵
* @param matrix 矩阵
* @param count 数据长度
* @return 数组
*/
PTriNode saveToTriNodeArray(PMatrix matrix, int *count)
{
    //n(n+1)/2;n为行总数
    const size_t length = matrix->rows * (matrix->rows + 1) / 2; //非零元素个数
    PTriNode a = (PTriNode)malloc(sizeof(TriNode) * length);     //创建一个数组
    int triangleIndex = 0;
    for (size_t matrixIndex = 0; matrixIndex < matrix->rows * matrix->columns; matrixIndex++)
    {
        const int value = *(matrix->table + matrixIndex);
        if (0 != value)
        {
            PTriNode triNode = (a + triangleIndex++);
            triNode->row = matrixIndex / matrix->columns;
            triNode->column = matrixIndex - triNode->row * matrix->columns;
            triNode->value = value;
        }
    }
    *count = length;
    return a;
}

/**
* 打印一维数组
* @param array 数组 
* @param lenght 数组长度
* @return 无
*/
void printTriNodeArray(PTriNode triNode, int length)
{
    for (size_t i = 0; i < length; i++)
    {
        printf("(%d,%d,%d),", triNode[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    PMatrix matrix = initMatix(5, 5);
    printMatrix(matrix);

    int lenght;
    PTriNode a = saveToTriNodeArray(matrix, &lenght);
    printTriNodeArray(a, lenght);

    return 0;
}