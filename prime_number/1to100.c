#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (size_t i = 2; i < 100; i++)
    {
        int isPrime = 1;
        for (size_t j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                isPrime = 0;
            }
        }
        if (isPrime)
        {
            printf(" %d,", i);
        }
    }
    printf("\n");

    return 0;
}