#include <stdio.h>

typedef struct _Point
{
    int x;
    int y;
} Point, *PPoint;

int main(int argc, char const *argv[])
{
    Point p = {.x = 10, .y = 20};

    PPoint pp1 = &p;
    PPoint pp2 = pp1;
    printf("x:%d,y:%d\n", *pp2);
    return 0;
}