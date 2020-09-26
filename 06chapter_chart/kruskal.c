#include <stdio.h>
#include "edge_set.h"

void sortWeightAscending(EdgeSet edgeSet[], int length)
{
    EdgeSet temp;
    for (size_t i = 0; i < length - 1; i++)
    {
        for (size_t j = i + 1; j < length; j++)
        {
            if (edgeSet[i].weight > edgeSet[j].weight)
            {
                temp = edgeSet[i];
                edgeSet[i] = edgeSet[j];
                edgeSet[j] = temp;
            }
        }
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
    EdgeSet edgeSet[] = {
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
    int length = sizeof(edgeSet) / sizeof(EdgeSet);
    sortWeightAscending(edgeSet, length);
    printEdgeSet(edgeSet, length);
    return 0;
}