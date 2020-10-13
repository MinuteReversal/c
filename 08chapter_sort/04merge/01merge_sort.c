/******************************************************************************
* fileName    : 01merge_sort.c 
* author      : 114233763@qq.com
* date        : 2020-10-13 20:31:10
* description : 归并排序
***************************************************************************** */
#include <stdio.h>
#define LENGTH 8

void merge(int sr[], int tr[], int m, int s, int t)
{
    int i, j, k;
    for (i = s, j = m + 1, k = s; i <= m && j <= t; k++)
    {
        if (sr[i] <= sr[j])
        {
            tr[k] = sr[i++];
        }
        else
        {
            tr[k] = sr[j++];
        }
    }

    while (i <= m)
    {
        tr[k] = sr[i];
        i++;
        k++;
    }
    while (j <= t)
    {
        tr[k] = sr[j];
        j++;
        k++;
    }
}

void mergePath(int r[], int a[], int n, int l)
{
    int p, i;
    p = 1;
    while (p + 2 * l - 1 <= n)
    {
        merge(r, a, p + l - 1, p, p + 2 * l - 1);
        p = p + 2 * l;
    }
    if (p + 1 - 1 < n)
    {
        merge(r, a, p + 1, p, n);
    }
    else
    {
        for (i = p; i <= n; i++)
        {
            a[i] = r[i];
        }
    }
    for (i = 1; i <= n; i++)
    {
        r[i] = a[i];
    }
}

int main(int argc, char const *argv[])
{
    int i;
    int sr1[LENGTH + 1],
        sr[LENGTH + 1] = {0, 42, 36, 56, 78, 67, 11, 27, 36};
    int l;
    l = 1;
    while (l < LENGTH)
    {
        mergePath(sr, sr1, LENGTH, l);
        l = 2 * l;
    }
    for (i = 1; i <= LENGTH; i++)
    {
        printf("%d,", sr1[i]);
    }
    printf("\n");

    return 0;
}