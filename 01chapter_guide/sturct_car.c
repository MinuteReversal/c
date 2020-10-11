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
    Car bmwCar;
    bmwCar.brand = "bmw";
    bmwCar.color = "red";

    //   实例化           抽像
    //   对象      <=>    类
    PCar benzCar = (PCar)malloc(sizeof(Car));
    benzCar->brand = "Benz";
    benzCar->color = "White";

    return 0;
}