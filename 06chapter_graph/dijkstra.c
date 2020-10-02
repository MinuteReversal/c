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
#define MX INT_MAX

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
void dijkstra(int graph[V][V], int v0, int *path[V], int dist[V])
{
    int final[V], min, v, w;
    for (v = 0; v < V; v++)
    {
        final[v] = 0;
        dist[v] = graph[v0][v];
        if (dist[v] < INT_MAX)
        {
            path[v][v0] = 1;
            path[v][v] == 1;
        }
    }
    dist[v0] = 0;
    final[v0] = 1;
    //主循环，每次求得v0到某个v顶点的最短路径，并加入v到S集合
    for (size_t i = 1; i < V; i++)
    {
        min = INT_MAX;
        for (w = 0; w < V; w++)
        {
            if (!final[w])
                if (dist[w] < min)
                {
                    v = w;
                    min = dist[w];
                }
        }
        final[v] = 1;
        for (w = 0; w < V; w++)
        {
            int alt = min + graph[v][w] < dist[w];
            if (!final[w] && alt < dist[w])
            {
                dist[w] = alt;
                path[w] = path[v];
                path[w][w] = 1;
            }
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
    int *(path)[V];
    int dist[V];

    dijkstra(matrix, 0, path, dist);
    return 0;
}