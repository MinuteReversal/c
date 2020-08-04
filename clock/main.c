#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    clock_t start, finish;
    double duration;

    start = clock();
    for (size_t i = 0; i < 1000000000L; i++)
    {
    }
    finish = clock();
    duration = (finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", duration);

    double time = difftime(finish, start);
    printf("%f seconds\n", time);
    return 0;
}