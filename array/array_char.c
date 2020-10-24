#include <stdio.h>
#define r 3
#define c 3

int main(int argc, char const *argv[])
{
    char a[r][c] = {{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}};
    int size = sizeof(int);
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            printf("%c,", *(a[i] + j));
        }
        printf("\n");
    }

    return 0;
}
