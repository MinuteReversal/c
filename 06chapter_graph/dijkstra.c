/******************************************************************************
* fileName    : dijkstra.c 
* author      : 114233763@qq.com
* date        : 2020-09-27 11:39:54
* description : 最短路径-迪杰斯特拉
https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
https://blog.csdn.net/qq_35644234/article/details/60870719
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#define V 6
#define MX 999

/**
 * 获取没有搜索过的最近距离顶点索引
 * @param dist 最近顶点
 * @param visited 已搜索过的标记
 * @return 最近顶点索引
 */
int minDistance(int dist[], int visited[])
{
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++)
        if (visited[v] == 0 && dist[v] <= min)
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
void dijkstra(int graph[V][V], int v0)
{
    int path[V], s[V], dist[V], i, j, w, v, min;

    for (i = 0; i < V; i++)
    {
        dist[i] = graph[v0][i];
        s[i] = 0;
        if (graph[v0][i] < MX)
            path[i] = v0;
    }

    s[v0] = 1;
    for (i = 0; i < V; i++)
    {
        min = MX;
        for (j = 0; j < V; j++)
            if ((s[j] == 0) && (dist[j] < min))
            {
                min = dist[j];
                w = j;
            }
        s[w] = 1;
        for (v = 0; v < V; v++)
        {
            if (!s[v] && dist[w] + graph[w][v] < dist[v])
            {
                dist[v] = dist[w] + graph[w][v];
                path[v] = w;
            }
        }
    }
    printf("The shortest path from %d to each vetex:\n", v0);

    for (i = 0; i < V; i++)
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
            printf(" %d\n", dist[i]);
        }
        else
        {
            printf("%d<--%d", i, v0);
            printf(" no path\n");
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
    int matrix[V][V] = {
        {MX, 50, 10, MX, 45, MX},
        {MX, MX, 15, MX, 10, MX},
        {20, MX, MX, 15, MX, MX},
        {MX, 20, MX, MX, 35, MX},
        {MX, MX, MX, MX, MX, MX},
        {MX, MX, MX, 3, MX, MX},
    };

    dijkstra(matrix, 5);
    return 0;
}