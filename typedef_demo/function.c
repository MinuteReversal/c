/******************************************************************************
* fileName    : function.c 
* author      : 114233763@qq.com
* date        : 2020-09-03 14:23:51
* description : 
***************************************************************************** */
#include <stdio.h>
#include "function.h"

int main(int argc, char const *argv[])
{
    PFN pfn = fn;
    (*pfn)(10, 20);
    return 0;
}