/******************************************************************************
* fileName    : hash_folding.c 
* author      : 114233763@qq.com
* date        : 2020-10-08 10:00:14
* description : 折叠法-键位数比地址位数多，分布不均匀。ISBN 0-442-20586-4。共有十位 0442205864
***************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

/**
 * 移位法
 */
int hashMove(int key)
{
    int low = key % 10000;
    int middle = key / 10000 % 10000;
    int high = key / 10000 / 10000 % 100;
    return (low + middle + high) % 10000;
}

int hashFolding(int key)
{
    int low = key % 10000;
    int middle = key / 10000 % 10000;
    int high = key / 10000 / 10000 % 100;

    //反转数组内容
    char rMiddle[5] = {0, 0, 0, 0, '\0'};
    itoa(middle, rMiddle, 10);
    char tmp = rMiddle[0];
    rMiddle[0] = rMiddle[3];
    rMiddle[3] = tmp;
    tmp = rMiddle[1];
    rMiddle[1] = rMiddle[2];
    middle = atoi(rMiddle);

    return (low + middle + high) % 10000;
}

int main(int argc, char const *argv[])
{
    int isbn = 442205864;
    int r1 = hashMove(isbn);
    int r2 = hashFolding(isbn);
    return 0;
}