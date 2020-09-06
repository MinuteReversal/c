#include <stdio.h>

int main(int argc, char const *argv[])
{

    int array[] = {0, 1, 2, 3, 4, 5};

    printf("%d\n", array == &array[0]);

    for (size_t i = 0; i < sizeof(array) / sizeof(int); i++)
    {
        printf("%d,", *(array + i));
    }
    printf("\n");

    for (size_t i = 0; i < sizeof(array) / sizeof(int); i++)
    {
        printf("%d,", array[i]);
    }
    printf("\n");

    for (size_t i = 0; i < sizeof(array) / sizeof(int); i++)
    {
        printf("%d,", *(array + i) == array[i]); //取值
    }
    printf("\n");

    for (size_t i = 0; i < sizeof(array) / sizeof(int); i++)
    {
        printf("%d,", (array + i) == &array[i]); //取地址
    }
    printf("\n");

    return 0;
}