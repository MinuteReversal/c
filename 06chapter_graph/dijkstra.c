/******************************************************************************
* fileName    : dijkstra.c 
* author      : 114233763@qq.com
* date        : 2020-09-27 11:39:54
* description : 最短路径-迪杰斯特拉
https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
***************************************************************************** */
#include <stdio.h>
#include <limits.h>
#define MAX_VEX 6
#define Q_MAX_LEN MAX_VEX *MAX_VEX
#include "../03chapter_stack_queue/sequence_queue.h"
#define MX INT_MAX

void printArray(int *array)
{
    for (size_t i = 0; i < MAX_VEX; i++)
    {
        printf("%d,", array[i]);
    }
    printf("\n");
}

void dijkstra(int graph[][MAX_VEX], int v0)
{
    PQueue q = createQueue();
    int dist[MAX_VEX];
    for (size_t v = 0; v < Q_MAX_LEN; v++)
    {
        dist[v] = MX;
        pushQueue(q, v);
    }

    //   for each vertex v in Graph:            
    //       dist[v] ← INFINITY                 
    //       prev[v] ← UNDEFINED                
    //       add v to Q                     
    //   dist[source] ← 0                       
     
    //   while Q is not empty:
    //       u ← vertex in Q with min dist[u]   
                                             
    //       remove u from Q
         
    //       for each neighbor v of u:           // only v that are still in Q
    //           alt ← dist[u] + length(u, v)
    //           if alt < dist[v]:              
    //               dist[v] ← alt
    //               prev[v] ← u

    //   return dist[], prev[]
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
    int matrix[MAX_VEX][MAX_VEX] = {
        {MX, 50, 10, MX, 45, MX},
        {MX, MX, 15, MX, 10, MX},
        {20, MX, MX, 15, MX, MX},
        {MX, 20, MX, MX, 35, MX},
        {MX, MX, MX, MX, MX, MX},
        {MX, MX, MX, 3, MX, MX},
    };
    dijkstra(matrix, 0);
    return 0;
}