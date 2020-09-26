/******************************************************************************
* fileName    : main.c 
* author      : 114233763@qq.com
* date        : 2020-09-26 14:43:24
* description : 指数与对数
  https://docs.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=vs-2019
***************************************************************************** */
#include <stdio.h>
#include <math.h>
#include <limits.h>

int main(int argc, char const *argv[])
{

  printf("%d\n", INT_MAX);
  printf("%d\n", (int)pow(2, 31));
  printf("%d\n", INT_MAX == (int)pow(2, 31));
  printf("%d\n", (1 << 31) - 1);

  printf("%f\n", log2(INT_MAX));
  return 0;
}