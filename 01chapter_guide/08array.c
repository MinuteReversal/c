#include <stdio.h>

int main(int argc, char const *argv[])
{
    int array[] = {1, 2, 3, 4, 5, 6};

    //遍历
    for (size_t i = 0; i < sizeof(array) / sizeof(int); i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}