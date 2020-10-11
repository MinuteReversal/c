/******************************************************************************
* fileName    : hanoi.c 
* author      : 114233763@qq.com
* date        : 2020-10-11 22:29:30
* description : 汉诺塔求解
***************************************************************************** */
#include <stdio.h>

/**
 * 打印步骤
 * @param plateNo 盘子编号
 * @param fromName 从哪
 * @param toName 到哪
 * @return 无
 */
void printMove(int plateNo, char fromName, char toName)
{
    printf("plate%d,%c => %c\n", plateNo, fromName, toName);
}

/**
 * 汉诺塔求解
 * @param n 盘子层数
 * @param a 柱
 * @param b 柱
 * @param c 柱
 * @return 无
 */
void hanoi(int n, char a, char b, char c)
{
    if (n == 1)
        printMove(1, a, c);
    else
    {
        hanoi(n - 1, a, c, b);
        printMove(n, a, c);
        hanoi(n - 1, b, a, c);
    }
}

int main(int argc, char const *argv[])
{
    int plates = 3;
    hanoi(plates, 'A', 'B', 'C');
    return 0;
}