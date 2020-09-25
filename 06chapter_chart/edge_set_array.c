/******************************************************************************
* fileName    : edges_set_array.c 
* author      : 114233763@qq.com
* date        : 2020-09-25 22:25:45
* description : 边集数组
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>
#define MAX_LEN 50

typedef struct _EdgeSet
{
    int beginVertex, endVertex, weight;
} EdgeSet, *PEdgeSet;

void printEdgeSet(PEdgeSet edgeSetArray, int length)
{
    printf("beginVertex\tendVertex\tweight\n");
    for (size_t i = 0; i < length; i++)
    {
        EdgeSet edgeSet = edgeSetArray[i];
        printf("%10d\t%9d\t%6d\n", edgeSet.beginVertex, edgeSet.endVertex, edgeSet.weight);
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
    EdgeSet array[] = {
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

    printEdgeSet(array, sizeof(array) / sizeof(EdgeSet));
    return 0;
}