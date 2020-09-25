#include <stdio.h>
#include <malloc.h>
#include "variable.h"
#include "function.h"
#include "struct.h"

typedef void *Handle; //可以指向任意类型

int main(int argc, char const *argv[])
{
    //handle可以转换为任意类型
    Handle p;

    Uint i = 888; //基础类型变量
    p = &i;       //赋值地址
    printf("%d\n", *(PUInt)p);

    p = fn;       //赋值函数
    ((PFN)(p))(); //调用

    p = (PPoint)malloc(sizeof(Point)); //赋值结构

    ((PPoint)p)->x = 10; //设置成员x的值
    ((PPoint)p)->y = 20; //设置成员y的值
    printf("%d\n", ((PPoint)p)->x + ((PPoint)p)->y);

    free(p);

    return 0;
}