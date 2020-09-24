/******************************************************************************
* fileName    : adjacency_matrix.c 
* author      : 114233763@qq.com
* date        : 2020-09-23 14:44:56
* description : 邻接矩阵
***************************************************************************** */

#include <stdio.h>
#define MAX_LEN 4

void init(int matrix[MAX_LEN][MAX_LEN])
{
    for (size_t i = 0; i < MAX_LEN; i++)
    {
        for (size_t j = 0; j < MAX_LEN; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void printMatrix(int matrix[MAX_LEN][MAX_LEN])
{
    for (size_t i = 0; i < MAX_LEN; i++)
    {
        for (size_t j = 0; j < MAX_LEN; j++)
        {
            printf("%d,", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{

    int adjMatrix[MAX_LEN][MAX_LEN] = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
    };

    printMatrix(adjMatrix);
    return 0;
}