#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 1;
    i = i + 1;
    printf("%d\n", i);

    
    for (size_t j = 0; j < 10; j++)
    {
        printf("%d\n", j);
    }

    return 0;
}