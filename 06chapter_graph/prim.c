/******************************************************************************
* fileName    : prim.c 
* author      : 114233763@qq.com
* date        : 2020-09-26 15:38:20
* description : 最小生成树-普里姆
***************************************************************************** */
#include <stdio.h>
#define MAX_LEN 6
#define M 2147483647

/**
 * 普里姆最小生成树
 * @param matrix 邻接矩阵
 * @param edgeNum 边总数
 */
void prim(int matrix[MAX_LEN][MAX_LEN], int edgeNum)
{
    int lowcost[MAX_LEN]; //最低成本
    int closest[MAX_LEN]; //最近点集合
    //初始化最小代价和最近集合
    for (size_t i = 0; i < edgeNum; i++)
    {
        lowcost[i] = matrix[0][i];
        closest[i] = 0;
    }

    closest[0] = -1; //选入U集合

    for (size_t i = 1; i < edgeNum; i++)
    {
        int min = M;
        int k = 0;
        for (size_t j = 0; j < edgeNum; j++)
        {
            if (closest[j] != -1 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
        }
        if (k)
        {
            printf("(%d,%d)%2d\n", closest[k], k, lowcost[k]);
            closest[k] = -1;
            for (size_t j = 1; j < edgeNum; j++)
            {
                if (closest[j] != -1 && matrix[k][j] < lowcost[j])
                {
                    lowcost[j] = matrix[k][j];
                    closest[j] = k;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /**
     *        (0) 
     *       / | \ 5
     *    6/   |1  \
     *   (1)   |   (2)
     *    |\5  |  5/|
     *    |  \ | /  |
     *   3|   (5)   |
     *    |  /   \4 | 2
     *    | /6    \ |
     *   (3)-------(4)
     *        6
     */
    int matrix[MAX_LEN][MAX_LEN] = {
        {M, 6, 5, M, M, 1},
        {6, M, M, 3, M, 5},
        {5, M, M, M, M, 2},
        {M, 3, M, M, 6, 6},
        {M, M, 2, 6, M, 4},
        {1, 5, 5, 6, 4, M},
    };

    prim(matrix, MAX_LEN);
    return 0;
}