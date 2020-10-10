#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 10;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            for (size_t k = 0; k < n; k++)
            {
                printf("%d%d%d,", i, j, k);
            }
        }
    }
    printf("\n");

    return 0;
}