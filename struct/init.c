#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point, *PPoint;

int main(int argc, char const *argv[])
{
    Point point = {10, 20};
    printf("x:%d,y:%d\n", point);
    Point point2 = {.x = 33, .y = 44};
    printf("x:%d,y:%d\n", point2);
    
    return 0;
}