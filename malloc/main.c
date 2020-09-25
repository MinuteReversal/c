#include <stdio.h>
#include <malloc.h>

int main(int argc, char const *argv[])
{
    int *p = (int *)malloc(sizeof(int));
    *p = 123;
    printf("%p\n", p);
    printf("%d\n", *p);
    free(p);
    return 0;
}