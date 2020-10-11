#include <stdio.h>
#define LENGTH 8

int main(int argc, char const *argv[])
{
    int r[LENGTH] = {42, 36, 56, 78, 67, 11, 27, 36};
    int temp;
    for (size_t i = 1; i < LENGTH; i++)
    {
        for (size_t j = 0; j < LENGTH; j++)
        {
            if (r[j] > r[j + 1])
            {
                temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;
            }
        }
    }

    for (size_t i = 0; i < LENGTH; i++)
    {
        printf("%d,", r[i]);
    }
    printf("\n");
    return 0;
}