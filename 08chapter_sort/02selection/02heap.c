#include <stdio.h>
#define LENGTH 9

void heapAdjust(int r[], int s, int m)
{
    int rc;
    rc = r[s];
    for (size_t i = 2 * s; i <= m; i *= 2)
    {
        if (i < m && r[i] <= r[i + 1])
        {
            i++;
        }
        if (rc > r[i])
        {
            break;
        }
        r[s] = r[i];
        s = i;
    }
    r[s] = rc;
}

int main(int argc, char const *argv[])
{
    int r[LENGTH] = {0, 42, 36, 56, 78, 67, 11, 27, 36};
    int i, x;
    for (size_t i = (LENGTH - 1) / 2; i > 0; i--)
    {
        heapAdjust(r, i, LENGTH - 1);
    }

    for (size_t i = LENGTH - 1; i > 1; --i)
    {
        x = r[1];
        r[1] = r[i];
        r[i] = x;
        heapAdjust(r, 1, i - 1);
    }

    for (size_t i = 1; i < LENGTH; i++)
    {
        printf("%d,", r[i]);
    }

    printf("\n");
    return 0;
}