#include <stdio.h>

void fn(int x)
{
    if (x > 0)
    {
        printf("%d\n", x);
        fn(x - 1);
    }
}

int main(int argc, char const *argv[])
{
    fn(10);
    return 0;
}