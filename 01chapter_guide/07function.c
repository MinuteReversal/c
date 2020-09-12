#include <stdio.h>

void fn1() { printf("fn1\n"); }

void fn2(int x) { printf("fn%d\n", x); }

int fn3() { return 3; }

int fn4(int x) { return x; }

int main(int argc, char const *argv[])
{
    fn1();
    fn2(2);
    int a = fn3();
    printf("%d\n", a);
    int b = fn4(4);
    printf("%d\n", b);
    return 0;
}