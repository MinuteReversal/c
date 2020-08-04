#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int i, n;
    time_t t;
    n = 5;

    srand((unsigned)time(&t));

    for (i = 0; i < 5; i++)
    {
        printf("%d\n", rand() % 50);
    }
    return 0;
}