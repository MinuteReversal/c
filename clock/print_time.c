#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    time_t t;
    printf("%d\n", time(&t));
    return 0;
}