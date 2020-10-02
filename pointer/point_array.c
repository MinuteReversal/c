#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 1;
    int b = 2;
    int *pa[2] = {&a, &b};

    printf("%d,\n", *pa[0]);
    printf("%d,\n", *pa[1]);
    printf("\n");

    return 0;
}