#include <stdio.h>

typedef struct _Point
{
    int x;
    int y;
} Point, *PPoint;

void changePointByVal(PPoint pPoint)
{
    Point p = {.x = 10, .y = 20};
    *pPoint = p;
}

void changePointByPointer(PPoint *pPoint)
{
    Point p = {.x = 100, .y = 100};
    *pPoint = &p;
}

int main(int argc, char const *argv[])
{

    Point p1;
    changePointByVal(&p1);
    printf("x:%d,y:%d\n", p1);

    PPoint pp1 = NULL;
    changePointByPointer(&pp1);
    printf("x:%d,y:%d\n", *pp1);
    return 0;
}