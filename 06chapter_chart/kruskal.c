/******************************************************************************
* fileName    : kruskal.c 
* author      : 114233763@qq.com
* date        : 2020-09-27 09:19:39
* description : 最小生成树-卡鲁斯卡尔
***************************************************************************** */
#include <stdio.h>
#include "edge_set.h"
#include "../02chapter_table/sequence_list.h"
#define MAX_VEX 50

/**
 * 按权升序
 * @param edgeSet 边集
 * @param length 长度
 * @return 无
 */
void sortAscending(EdgeSet edgeSet[], int length)
{
    EdgeSet temp;
    for (size_t i = 0; i < length - 1; i++)
    {
        for (size_t j = i + 1; j < length; j++)
        {
            if (edgeSet[i].weight > edgeSet[j].weight)
            {
                temp = edgeSet[i];
                edgeSet[i] = edgeSet[j];
                edgeSet[j] = temp;
            }
        }
    }
}

/**
 * 找连通分量的根结点
 * @param set 集合
 * @param vertex 顶点
 * @return 顶点
 */
int seeks(int set[], int vertex)
{
    int i = vertex;
    while (set[i] > 0)
    {
        i = set[i];
    }
    return i;
}

/**
 * 卡鲁斯卡尔
 * @param edgeNum 边数
 * @return 无
 */
void kruskal(EdgeSet edgeSet[], int edgeNum)
{
    int set[MAX_VEX];
    initArrayByZero(set, MAX_VEX);
    printf("Output of Kruskal:\n");

    int i = 0, v1, v2;
    while (i < edgeNum)
    {
        v1 = seeks(set, edgeSet[i].beginVertex);
        v2 = seeks(set, edgeSet[i].endVertex);
        if (v1 != v2)
        {
            printf("(%d,%d) %d\n", edgeSet[i].beginVertex, edgeSet[i].endVertex, edgeSet[i].weight);
            set[v1] = v2;
        }
        i++;
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
    EdgeSet edgeSet[] = {
        {0, 1, 6},
        {0, 2, 5},
        {0, 5, 1},
        {1, 3, 3},
        {1, 5, 5},
        {2, 5, 5},
        {2, 4, 2},
        {3, 5, 6},
        {3, 4, 6},
        {4, 5, 4},
    };
    int length = sizeof(edgeSet) / sizeof(EdgeSet);
    sortAscending(edgeSet, length);
    printEdgeSet(edgeSet, length);
    kruskal(edgeSet, 10);
    return 0;
}