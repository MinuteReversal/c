/******************************************************************************
* fileName    : floyed.c 
* author      : 114233763@qq.com
* date        : 2020-09-29 09:28:56
* description : 最短路径-弗洛伊德
https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
***************************************************************************** */
#include <stdio.h>
#include <limits.h>

#define M INT_MAX
#define V 3

/* A utility function to print solution */
void printSolution(int dist[][V])
{
    printf("The following matrix shows the shortest distances"
           " between every pair of vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == M)
                printf("%s,", "Infinite");
            else
                printf("(%d-->%d) %d, ", i, j, dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][V])
{
    int dist[V][V], i, j, k;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (i = 0; i < V; i++)
            dist[i][i] = 0;

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist);
}

int main(int argc, char const *argv[])
{
    /**
     * 
     *        /->(0)<-\
     *      6/  /   \  \3
     *      /  /4  11\  \
     *      \ V       V /
     *      (1)------>(2)
     *           2
     */

    int matrix[V][V] = {
        {M, 4, 11},
        {6, M, 2},
        {3, M, M},
    };

    floydWarshall(matrix);

    return 0;
}