#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 10;
    for (size_t i = 1; i < n; i++)
    {
        for (size_t j = 1; j < n; j++)
        {
            printf("%dx%d=%d ", j, i, j * i);
        }
        printf("\n");
    }

    return 0;
}