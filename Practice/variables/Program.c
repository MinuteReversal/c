#include "stdio.h"

int main(int argc, char *argv[], char *envp[])
{
    int a = 1, b = 2, c = 3;
    ++a;
    c += ++b;
    {
        int a = 4, c;
        c = b * 3;
        a += c;
        printf("first:%d,%d,%d\n", a, b, c);
        b += a + c;
        printf("second:%d,%d,%d\n", a, b, c);
    }
    printf("third:%d,%d,%d\n", a, b, c);
    return 0;
}