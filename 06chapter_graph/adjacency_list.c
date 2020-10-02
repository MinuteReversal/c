/******************************************************************************
* fileName    : adjacency_list.c 
* author      : 114233763@qq.com
* date        : 2020-09-24 21:31:55
* description : 邻接表
***************************************************************************** */
#include <stdio.h>
#include "adjacency_list.h"

int main(int argc, char const *argv[])
{
    /**
     * (v0)------(v2)
     *  | \      /
     *  |   \  /
     *  |    /\
     *  |  /    \
     * (v1)------(v3)
     * 
     * 0 [v0]->[1]->[2]->[3]
     * 1 [v1]->[0]->[2]->[3]
     * 2 [v2]->[0]->[1]
     * 3 [v3]->[0]->[1]
     */
    PHeadNode head[MAX_LEN];
    head[0] = createRow((int[]){0, 1, 2, 3}, 4);
    head[1] = createRow((int[]){1, 0, 2, 3}, 4);
    head[2] = createRow((int[]){2, 0, 1}, 3);
    head[3] = createRow((int[]){3, 0, 1}, 3);

    printList(head, MAX_LEN);
    return 0;
}