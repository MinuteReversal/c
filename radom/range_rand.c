#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int upperLimit = 100;
    int lowerLimit = 0;
    srand(time(NULL));
    printf("%d\n", rand());
    return 0;
}