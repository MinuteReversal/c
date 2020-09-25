#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("%d\n", 123); //整数
    printf("%u\n", 123); //无符号
    printf("%x\n", 123); //十六进制
    printf("%s\n", "hello world");
    printf("%#x\n", 8);
    int *p;
    printf("%p\n", p);
    return 0;
}