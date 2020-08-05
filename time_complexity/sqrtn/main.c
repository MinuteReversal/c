#include <stdio.h>
//等差数列m(m+1)/2
int main(int argc, char const *argv[])
{
    int i=0, s=0, n=10;
    while (s<n)
    {
        ++i;
        s=s+i;
    }
    printf("%d\n",s);
    return 0;
}