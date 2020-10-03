/******************************************************************************
* fileName    : topo_sort.c 
* author      : 114233763@qq.com
* date        : 2020-10-02 22:04:35
* description : topology - 拓扑排序
***************************************************************************** */
#include <stdio.h>
#include "adjacency_list.h"
#include "../03chapter_stack_queue/circular_queue.h"
#define N 6

/**
 * 拓扑排序
 * @param adjList 邻接表
 * @return 无
 */
void topSort(PHeadNode adjList[N])
{
    PQueue queue = createQueue();
    PNode p;
    int v, w, n1;
    n1 = 0;
    for (v = 0; v < N; v++)
    {
        if (adjList[v]->data == 0)
        {
            pushQueue(queue, v);
        }
    }
    printf("Result of toposort is:  ");
    while (!isEmptyQueue(queue))
    {
        popQueue(queue, &v);
        printf("%d,", v);
        n1++;
        p = adjList[v]->firstEdge;
        while (p)
        {
            w = p->vertex;
            adjList[w]->data--; //将邻接于顶点V的顶点的入度减1
            if (adjList[w]->data == 0)
            {
                pushQueue(queue, w);
            }
            p = p->next;
        }
    }
    if (n1 < N)
    {
        printf("Not a set of partial order.\n");
    }
}

int main(int argc, char const *argv[])
{
    /**
     * 
     *   (0)------>(2)------->(4)------->(5)
     *     \       ^         ^ ^ \       ^   
     *       \    /       /   /   \   /   
     *         \/     /     /     /\  
     *        /  \ /      /    /    \
     *      /   / \     /   /        \
     *    /  /      v /  /            v
     *   (1)------>(3) /              (6)
     */
    PHeadNode head[N];
    head[0] = createRow((int[]){0, 2, 3}, 3);
    head[1] = createRow((int[]){0, 2, 4}, 3);
    head[2] = createRow((int[]){0, 4}, 2);
    head[3] = createRow((int[]){0, 4, 5}, 3);
    head[4] = createRow((int[]){0, 5, 6}, 3);
    head[5] = createRow((int[]){0}, 1);
    head[6] = createRow((int[]){0}, 1);

    //入度设置
    head[0]->data = 0;
    head[1]->data = 0;
    head[2]->data = 2;
    head[3]->data = 2;
    head[4]->data = 3;
    head[5]->data = 2;
    head[6]->data = 1;

    topSort(head);
    printf("\n");
    return 0;
}