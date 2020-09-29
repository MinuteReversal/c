#include <stdio.h>

int main(int argc, char const *argv[])
{
    //整型
    printf("%d\n", 30u);
    printf("%d\n", 30l);
    printf("%d\n", 010);
    printf("%d\n", 0xFF);
    printf("%d\n", 201L);

    //浮点型
    printf("%f", 3.14);
    printf("%f", 314159E-5L);

    //字符串
    printf("%d\n", 'A');
    printf("%s\n", "hello "
                   "world");
    printf("%s\n", "hello "
                   "d"
                   "ear");
    return 0;
}