#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}