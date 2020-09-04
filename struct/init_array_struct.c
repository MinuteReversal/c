#include <stdio.h>
typedef struct _Box
{
    int width;
    int height;
} Box, *PBox;

void printBox(Box box)
{
    printf("width:%d,height:%d\n", box);
}

int main(int argc, char const *argv[])
{
    Box boxes[3] = {10, 10, 20, 20, 30, 30};
    printBox(boxes[0]);
    printBox(boxes[1]);
    printBox(boxes[2]);
    return 0;
}