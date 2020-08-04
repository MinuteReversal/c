#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (int i = 1; i < 10; i++) //n
    {
        for (int j = 1; j <= i; j++) //n*n
        {
            printf("%dx%d=%d\t", j, i, i * j); //n*n/2
        }
        printf("\n");
    }

    //时间复杂度为:n+n²+n²/2=O(n²)
    return 0;
}