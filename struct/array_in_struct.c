#include <stdio.h>
typedef struct
{
    int arr[100];
    int len;
} SqList;

int main(int argc, char const *argv[])
{
    SqList list = {1, 2, 3, 4};

    printf("%d,%d\n", list);
    return 0;
}