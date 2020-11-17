/******************************************************************************
* fileName    : sturct_bag.c 
* author      : 114233763@qq.com
* date        : 2020-10-11 21:49:32
* description : 面向对象示例
***************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

typedef struct _Bag
{
    //牌子
    char *brand;
    //颜色
    char *color;
} Bag, *PBag;

int main(int argc, char const *argv[])
{
    //值类型
    Bag lvBag;
    lvBag.brand = (char*)"lv";
    lvBag.color = (char*)"red";

    //引用类型
    //   实例化           抽像
    //   对象      <=>    类
    PBag chanelBag = (PBag)malloc(sizeof(PBag));
    chanelBag->brand = (char*)"chanel";
    chanelBag->color = (char*)"white";

    return 0;
}