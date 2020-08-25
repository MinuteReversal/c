#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[] = {5, 3, 7, 9, 8, 4, 2, 1, 6};
    int length = sizeof(a) / sizeof(int);

    for (int i = 0; i < length; i++)
    {
        int minIndex = i;
        for (int j = i; j < length; j++)
        {
            minIndex = a[minIndex] > a[j] ? j : minIndex;
        }
        //交换
        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }

    for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        printf("%d\n", a[i]);
    }
    
    return 0;
}