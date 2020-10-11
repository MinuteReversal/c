#include <stdio.h>

int main(int argc, char const *argv[])
{
    int array[5];
    //                  边界
    for (size_t i = 0; i < 5; i++)
    {
        array[i] = i;
    }

    for (size_t i = 0; i < 5; i++)
    {
        array[i] = i + 1;
    }

    return 0;
}