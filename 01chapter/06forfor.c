#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (size_t i = 1; i < 10; i++)
    {
        for (size_t j = 1; j < 10; j++)
        {
            printf("%dx%d=%d\t", j, i, i * j);
        }
        printf("\n");
    }

    return 0;
}