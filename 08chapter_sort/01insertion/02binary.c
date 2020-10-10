/******************************************************************************
* fileName    : 02binary.c 
* author      : 114233763@qq.com
* date        : 2020-10-10 21:57:00
* description : 折半查找
***************************************************************************** */
#include <stdio.h>

void printList(int r[], int length)
{

    for (size_t i = 0; i < length; i++)
    {
        printf("%d,", r[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int i, j, low, high, m, t = 0;
    int n = 8;
    int r[] = {42, 36, 56, 78, 67, 11, 27, 36};
    for (size_t i = 1; i < n; i++)
    {
        t = r[i];
        low = 0;
        high = i - 1;
        while (low <= high)
        {
            m = (low + high) / 2;
            if (t < r[m])
            {
                high = m - 1;
            }
            else
            {
                low = m + 1;
            }
        }

        //插入操作
        for (j = i - 1; j > high; j--)
        {
            r[j + 1] = r[j];
        }
        r[j + 1] = t;

        printf("第%d趟\n", i);
        printList(r, n);
    }

    return 0;
}