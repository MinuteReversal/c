/******************************************************************************
* fileName    : dijkstra.c 
* author      : 114233763@qq.com
* date        : 2020-09-27 11:39:54
* description : 最短路径-迪杰斯特拉
***************************************************************************** */
#include <stdio.h>
#include <limits.h>
#define INPUT_MATRIX_LEN 6
#include "../02chapter_table/matrix.h"
#define MX INT_MAX
#define MAX_VEX 10

void printArray(int *array){
    for (size_t i = 0; i < MAX_VEX; i++)
    {
        printf("%d,",array[i]);
    }
    printf("\n");
}

void dijkstra(int **matrix, int vertexNum, int v0)
{
    int path[MAX_VEX], s[MAX_VEX], dist[MAX_VEX], w;
    for (size_t i = 0; i < vertexNum; i++)
    {
        dist[i] = matrix[v0][i];
        s[i] = 0;
        if (matrix[v0][i] < MX)
        {
            path[i] = v0;
        }
        printArray(path);
    }
    s[v0] = 1;
    for (size_t i = 0; i < vertexNum; i++)
    {
        int min = MX;
        for (size_t j = 0; j < vertexNum; j++)
        {
            if (s[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                w = j;
            }
        }
        s[w] = 1;
        for (size_t v = 0; v < vertexNum; v++)
        {
            if (s[v] == 0)
            {
                if (dist[w] + matrix[w][v] < dist[v])
                {
                    dist[v] = dist[w] + matrix[w][v];
                    path[v] = w;
                    printArray(path);
                }
            }
        }
    }
    printf("the shortest path from %d to each vertex:\n", v0);
    for (size_t i = 1; i < vertexNum; i++)
    {
        if (s[i] == 1)
        {
            w = i;
            while (w != v0)
            {
                printf("%d<--", w);
                w = path[w];
            }
            printf("%d", w);
            printf("%d\n", dist[i]);
        }
        else
        {
            printf("%d<--%d", i, v0);
            printf("no path\n");
        }
    }
}

int main(int argc, char const *argv[])
{

    /**     
     *             45
     *       /-------------\
     *     /  50       10   V
     *   (0)------>(1)----->(4)
     *   | ^      / ^       ^
     * 10| |20  /   | 20  / 35
     *   | |  /15   |   / 
     *   V |V       | /
     *   (2)------>(3)<-----(5)
     *        15         3
     */
    int m[INPUT_MATRIX_LEN][INPUT_MATRIX_LEN] = {
        {MX, 50, 10, MX, 45, MX},
        {MX, MX, 15, MX, 10, MX},
        {20, MX, MX, 15, MX, MX},
        {MX, 20, MX, MX, 35, MX},
        {MX, MX, MX, MX, MX, MX},
        {MX, MX, MX, 03, MX, MX},
    };
    int **adjMatrix = create(m, INPUT_MATRIX_LEN);
    dijkstra(adjMatrix, 6, 0);
    disposeMatrixArray(adjMatrix);
    return 0;
}