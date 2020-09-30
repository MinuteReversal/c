/******************************************************************************
* fileName    : dijkstra.c 
* author      : 114233763@qq.com
* date        : 2020-09-27 11:39:54
* description : 最短路径-迪杰斯特拉
https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#define V 6
#define MX INT_MAX

/**
 * 获取没有搜索过的最近距离顶点索引
 * @param dist 最近顶点
 * @param sptSet 已搜索过的标记
 * @return 最近顶点索引
 */
int minDistance(int dist[], int sptSet[])
{
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], minIndex = v;

    return minIndex;
}

/**
 * 打印最近距离
 */
void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

/**
 * 迪杰斯特拉
 * 单次获取最近的顶点
 * @param graph 图
 * @param src 起始顶点
 * @return 返回src到最近顶点的索引与距离
 */
int *dijkstra(int graph[V][V], int src)
{
    int *dist = (int *)malloc(V * sizeof(int));
    int sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        for (int v = 0; v < V; v++)
        {
            int alt = dist[u] + graph[u][v];
            if (!sptSet[v] && alt < dist[v])
            {
                dist[v] = alt;
                printf("%d=>", u);
            }
        }
    }

    return dist;
}

int findMinIndex(int dist[V])
{
    int min = -1;
    int index = 0;
    for (size_t i = 0; i < V; i++)
    {
        if (min < dist[i] && dist[i] > 0 && dist[i] < MX)
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

/**
 * 两点之间最短路径
 * @param graph 图
 * @param from 开始点
 * @param to 结束点
 * @return 路径
 */
int *shortPath(int graph[V][V], int from, int to)
{
    int next = from;
    int path[V] = {0, 0, 0, 0, 0, 0};
    int *dist;

    while (next != to)
    {
        dist = dijkstra(graph, from);
        next = findMinIndex(dist);
    }
    return path;
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
    int matrix[V][V] = {
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