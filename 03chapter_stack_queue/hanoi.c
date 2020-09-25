#include <stdio.h>

void move(int plateNo, char fromName, char toName)
{
    printf("plate%d,%c => %c\n", plateNo, fromName, toName);
}

void hanoi(int n, char a, char b, char c)
{
    if (n == 1)
        move(1, a, c);
    else
    {
        hanoi(n - 1, a, c, b);
        move(n, a, c);
        hanoi(n - 1, b, a, c);
    }
}

int main(int argc, char const *argv[])
{
    int plates = 3;
    hanoi(plates, 'A', 'B', 'C');
    return 0;
}