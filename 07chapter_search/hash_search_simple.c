#include <stdio.h>
#include "../02chapter_list/sequence_list.h"
#define MAX_LEN 50

/**
 * 散列算法产生索引号
 * @param data 数据
 * @return index
 */
int hash(int data)
{
    int index = data % 100;
    return index;
}

/**
 * 保存到数组中
 * @param data 数据
 */
void save(int data, int array[MAX_LEN])
{
    int index = hash(data);
    array[index] = data;
}

/**
 * 查找
 * @param data 数据
 * @param array 数组
 * @return index
 */
int search(int data, int array[MAX_LEN])
{
    int index = hash(data);
    if (array[index] > 0)
    {
        return index;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int array[MAX_LEN];
    initArrayByZero(array, MAX_LEN);

    save(200201, array);
    save(200205, array);
    save(200218, array);
    save(200221, array);
    save(200227, array);
    save(200245, array);

    int number = 200201;
    int index = search(number, array);

    if (index > -1)
    {
        printf("%d的索引号是%d\n", number, index);
    }
    else
    {
        printf("没有此学号%d\n", number);
    }

    return 0;
}