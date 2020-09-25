#include <stdio.h>

struct Point
{
    int x;
    int y;
};

int main(int argc, char const *argv[])
{
    struct Point point;
    point.x = 10;
    point.y = 20;

    return 0;
}