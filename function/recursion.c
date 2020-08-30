#include <stdio.h>

int add(int x)
{
    if (x > 1)
    {
        return x + add(x - 1);
    }
    return x;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", add(100));
    return 0;
}