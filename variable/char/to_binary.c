#include <stdio.h>

int main(int argc, char const *argv[])
{

    unsigned char a = 10;
    int i;
    for (i = 0; i < 8; i++)
    {
        printf("%d", !!((a << i) & 0x80));
    }
    printf("\n");

    return 0;
}