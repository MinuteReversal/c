#include <stdio.h>

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
PMatrix init(int row, int column)
{
    int table[row][column];

    Matrix matrix = {
        .column = column,
        .row = row,
        .table = table[0],
    };

    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < column; c++)
        {
            table[r][c] = 1;
        }
    }
    PMatrix pMatrix = &matrix;
    return pMatrix;
}

void printMatrix(PMatrix matrix)
{
    int count = 0;
    const int *table = matrix->table;
    const int rows = matrix->row;
    const int columns = matrix->column;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            printf("%d,", *(table + count++));
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    PMatrix matrix = init(5, 5);
    printMatrix(matrix);
    return 0;
}