#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 123;
    int *pi1 = &i;
    int *pi2 = &i;
    int *pi3 = &i;

    *pi2 = 888;

    printf("%d\n", i);
    printf("%d\n", *pi1);
    printf("%d\n", *pi2);
    printf("%d\n", *pi3);
    return 0;
}