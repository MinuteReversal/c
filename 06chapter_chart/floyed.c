/******************************************************************************
* fileName    : floyed.c 
* author      : 114233763@qq.com
* date        : 2020-09-29 09:28:56
* description : 最短路径-弗洛伊德
***************************************************************************** */
#include <stdio.h>
#include <limits.h>
#include "../02chapter_table/matrix.h"

#define M INT_MAX

int main(int argc, char const *argv[])
{
    /**
     * 
     *        /->(0)<-\
     *      6/  /  \   \3
     *      /  /4 11\   \
     *      \ V      V  /
     *      (1)------>(2)
     *           2
     */

    int m[3][3] = {
        {M, 4, 11},
        {6, M, 2},
        {3, M, M},
    };

    return 0;
}