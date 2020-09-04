#include <stdio.h>
typedef struct
{
    int arr[100];
    int len;
} SqList;

void printSqList(SqList list)
{
    for (int i = 0; i < list.len; i++)
    {
        printf("%d,", list.arr[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    SqList sqList = {0, 1, 2, 3, 4};
    sqList.len = 5;
    printSqList(sqList);

    SqList sqList2 = {
        .arr = {0, 1, 2, 3, 4},
        .len = 5,
    };

    printSqList(sqList2);

    return 0;
}