#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *a = "12345";
    int b = atoi(a);

    int x = 8888;
    char y[4];
    itoa(x, y, 10);
    return 0;
}