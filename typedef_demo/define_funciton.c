#include <stdio.h>

typedef void *Handle;

void fn()
{
    printf("hello world");
}

int main(int argc, char const *argv[])
{
    Handle p = fn;
    return 0;
}