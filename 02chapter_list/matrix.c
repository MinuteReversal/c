#include <stdio.h>
#include "matrix.h"

int main(int argc, char const *argv[])
{
    PMatrix m = initMatix(5, 5); //创建5x5的矩阵
    printMatrix(m);              //打印矩阵
    disposeMatrix(m);            //释放矩阵
    return 0;
}