#include <stdio.h>

int main(int argc, char const *argv[])
{
    int cup1 = 1;
    int cup2 = 3;
    int cup3 = 0;

    printf("cup1=%d,cup2=%d\n", cup1, cup2);

    cup3 = cup2;
    cup2 = cup1;
    cup1 = cup3;

    printf("cup1=%d,cup2=%d\n", cup1, cup2);

    return 0;
}