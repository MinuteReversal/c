#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    int p = (int)&i;

    printf("#%p\n", &i);
    printf("#%p\n", p);

    printf("sizeof int %d\n", sizeof(int));
    printf("sizeof int * %d\n", sizeof(int *));
    return 0;
}