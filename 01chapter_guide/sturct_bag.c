#include <stdio.h>
#include <malloc.h>

typedef struct _Bag
{
    //牌子
    char *brand;
    //颜色
    char *color;
} Bag, *PBag;

int main(int argc, char const *argv[])
{
    Bag lvBag;
    lvBag.brand = "lv";
    lvBag.color = "red";

    PBag chanelBag = (PBag)malloc(sizeof(PBag));
    chanelBag->brand = "chanel";
    chanelBag->color = "White";

    return 0;
}