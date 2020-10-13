/******************************************************************************
* fileName    : link_radix.c 
* author      : 114233763@qq.com
* date        : 2020-10-13 09:02:51
* description : 链式基数排序
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>

typedef struct _Node
{
    int key;
    struct _Node *next;
} Node, *PNode;

PNode create(int value)
{
    PNode node = (PNode)malloc(sizeof(Node));
    node->key = value;
    node->next = NULL;
}

PNode initFromArray(int array[], int length)
{
    PNode head = create(-1);
    PNode node = head;
    for (size_t i = 0; i < length; i++)
    {
        node->next = create(array[i]);
        node = node->next;
    }
    return head;
}

PNode radixSort(PNode h, int d, int R)
{
    int i, j, s, k, m;
    PNode f[10], r[10], p, q;
    s = 1;
    m = R;
    p = h->next;
    for (i = 1; i <= d; i++)
    {
        for (j = 0; j < R; j++)
        {
            f[j] = NULL;
            r[j] = NULL;
        }
        q = p;
        while (q != NULL)
        {
            k = (q->key % m) / s;
            if (f[k] == NULL)
            {
                f[k] = q;
            }
            else
            {
                r[k]->next = q;
            }
            r[k] = q;
            q = q->next;
        }
        p = NULL;
        for (j = R - 1; j >= 0; j--)
        {
            if (f[j] != NULL)
            {
                r[j]->next = p;
                p = f[j];
            }
        }
        m = m * 10;
        s = s * 10;
    }
    h->next = p;
    return h;
}

int main(int argc, char const *argv[])
{
    int d = 3;
    int R = 10;
    PNode a, b;
    a = initFromArray((int[]){
                          387,
                          456,
                          592,
                          625,
                          76,
                          471,
                          50,
                          96,
                          557,
                          522,
                      },
                      10);
    b = radixSort(a, d, R);
    b = b->next;
    while (b != NULL)
    {
        printf("%d,", b->key);
        b = b->next;
    }

    return 0;
}