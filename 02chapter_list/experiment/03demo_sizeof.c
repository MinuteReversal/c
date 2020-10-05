#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 123;
    printf("%d\n", sizeof(i));
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(char));
    printf("%d\n", sizeof(float));
    printf("%d\n", sizeof(double));
    return 0;
}