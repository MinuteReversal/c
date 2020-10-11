/******************************************************************************
* fileName    : sturct_car.c 
* author      : 114233763@qq.com
* date        : 2020-10-11 21:50:03
* description : 面向对象
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>

typedef struct _Car
{
    //牌子
    char *brand;
    //颜色
    char *color;
} Car, *PCar;

int main(int argc, char const *argv[])
{
    //值类型
    Car bmwCar;
    bmwCar.brand = "bmw";
    bmwCar.color = "red";

    //引用类型
    //   实例化           抽像
    //   对象      <=>    类
    PCar benzCar = (PCar)malloc(sizeof(Car));
    benzCar->brand = "Benz";
    benzCar->color = "White";
    free(benzCar);

    return 0;
}