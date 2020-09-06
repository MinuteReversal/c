
#include <stdio.h>

void printTable(int *a)
{
    int intSize = sizeof(int);
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            printf("%d,", *(a + i * intSize + j));
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int a[3][4] = {
        {1, 3, 5, 7},
        {9, 11, 13, 15},
        {17, 19, 21, 23},
    };

    int cells = sizeof(a) / sizeof(int);
    int columns = sizeof(*a) / sizeof(int);
    int rows = cells / columns; //无法获得行数，只能通过总数/列数获得
    int intSize = sizeof(int);
    printf("size of int is %d\n", intSize);
    printf("cells length is %d\n", cells);
    printf("rows length is %d\n", rows);
    printf("columns length is %d\n", columns);

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            printf("%d,", *(a[i] + j)); //二维数组第一维存的全是地址
        }
        printf("\n");
    }

    for (int *p = a[0]; p < a[0] + cells; p++)
    {
        if ((p - a[0]) % 4 == 0)
        {
            printf("\n");
        }
        printf("%d,", *p);
    }
    printf("\n");

    printTable(*a);

    return 0;
}