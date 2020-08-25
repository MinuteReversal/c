#include <stdio.h>

void fn1()
{
    printf("fn%d\n", 1);
}

void fn2(int x)
{
    printf("fn%d\n", x);
}

int fn3()
{
    return 3;
}

int fn4(int x)
{
    return x;
}

int main(int argc, char const *argv[])
{
    void (*p1)() = fn1;
    void (*p2)(int) = fn2;
    int (*p3)() = fn3;
    int (*p4)(int) = fn4;

    fn1();
    fn2(2);
    printf("fn%d\n", fn3());
    printf("fn%d\n", fn4(4));

    printf("==================\n");

    p1();
    p2(2);
    printf("fn%d\n", p3());
    printf("fn%d\n", p4(4));

    return 0;
}