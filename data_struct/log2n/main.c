#include <stdio.h>

int main(int argc, char const *argv[])
{
    size_t i = 1, n = 10;      //1+1
    for (i = 1; i < n; i *= 2) //log2N
    {
        printf("%d\n", i);//log2N
    }

    //a^x=n
    //x=logan
    //x=log₂n
    printf("i最终值:%d\n", i);//1

    //O(log2n)=log2N+log2N+2;
    return 0;
}