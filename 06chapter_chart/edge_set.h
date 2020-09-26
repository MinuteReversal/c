/******************************************************************************
* fileName    : edges_set_array.c 
* author      : 114233763@qq.com
* date        : 2020-09-25 22:25:45
* description : 边集数组
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>

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
