#include <stdio.h>
#include <malloc.h>

typedef struct _Point
{
    int x;
    int y;
} Point, *PPoint;

int main(int argc, char const *argv[])
{
    Point a = {x : 10, y : 10};
    PPoint b1 = &a;
    PPoint b = (Point *)malloc(sizeof(Point));
    b->x = 20;
    b->y = 20;

    printf("x:%d,y:%d\n", a.x, a.y);
    printf("x:%d,y:%d\n", b->x, b->y);
    return 0;
}