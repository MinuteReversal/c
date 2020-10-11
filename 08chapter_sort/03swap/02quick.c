#include <stdio.h>
#define LENGTH 8

int partition(int r[], int s, int t)
{
    int i, j, rp;
    i = s;
    j = t;
    rp = r[s];
    while (i < j)
    {
        while (i < j && r[j] >= rp)
        {
            j--;
        }
        r[i] = r[j];
        while (i < j && r[i] <= rp)
        {
            i++;
        }
        r[j] = r[i];
    }
    r[i] = rp;
    return i;
}

void quickSort(int r[], int s, int t)
{
    int k;
    if (s < t)
    {
        k = partition(r, s, t);
        quickSort(r, s, k - 1);
        quickSort(r, k + 1, t);
    }
}

int main(int argc, char const *argv[])
{
    int i;
    int r[LENGTH] = {42, 36, 56, 78, 67, 11, 27, 36};
    quickSort(r, 0, LENGTH - 1);
    for (size_t i = 0; i < LENGTH; i++)
    {
        printf("%d,", r[i]);
    }

    return 0;
}