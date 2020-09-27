#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[] = {0, 1, 2, 3, 4};
    int *pa = a;

    printf("%d\n", a);
    printf("%d\n", pa);
    printf("%d\n", a[0]);
    printf("%d\n", *pa);
    printf("%d\n", a[1]);
    printf("%d\n", *(pa + 1));
    return 0;
}