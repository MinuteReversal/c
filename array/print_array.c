#include <stdio.h>

void print(int *array, int length)
{
    for (size_t i = 0; i < length; i++)
    {
        printf("%d,", array[i]);
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    int a[5] = {1, 2, 3, 4, 5};
    print(a, 5);
    return 0;
}