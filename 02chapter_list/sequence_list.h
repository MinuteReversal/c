#include <stdio.h>
#include <malloc.h>
#define MAX_LIST_LENGTH 100

typedef struct _List
{
    int array[MAX_LIST_LENGTH];
    int length;
} List, *PList;

/**
 * 创建顺序表
 * @param length 表长度
 */
PList createList(int length)
{
    PList list = (PList)malloc(sizeof(List));
    list->length = length;
    return list;
}

/**
 * 创建顺序表并初始化为0
 * @param length 表长度
 */
PList createListInitZero(int length)
{
    PList list = createList(length);
    for (size_t i = 0; i < length; i++)
    {
        list->array[i] = 0;
    }
    return list;
}

/**
 * 创建数组
 * @param length 长度
 * @return 数组
 */
int *createArrayInitZero(int length)
{
    int array[length];
    for (size_t i = 0; i < length; i++)
    {
        array[i] = 0;
    }
    int *pa = array;
    return pa;
}

/**
 * 将数组的每一个成员赋值为0
 * @param array 数组
 * @param length 长度
 * @return 无
 */
void initArrayByZero(int array[], int length)
{
    for (size_t i = 0; i < length; i++)
    {
        array[i] = 0;
    }
}

/**
 * 将第二组的值复制到第一组中
 * @param array1 第一组
 * @param array2 第二组
 * @return 无
 */
void copyArray(int array1[], int array2[], int length)
{
    for (size_t i = 0; i < length; i++)
    {
        array1[i] = array2[i];
    }
}

/**
 * 使用列表类型初始化顺序表 
 */
PList createListByArray(int *array, int length)
{

    PList plist = createList(length);
    copyArray(plist->array, array, length);
    plist->length = length;
    return plist;
}

/**
 * 在指定位置前插入一个元素
 * 返回值 0 为错误 1为正常
 */
int insertBefore(int index, int value, PList list)
{
    //插入位置超过范围
    if (index > list->length || index < 1)
    {
        return 0;
    }

    //向后搬砖
    for (int i = list->length; i >= index; i--)
    {
        list->array[i + 1] = list->array[i];
    }

    list->array[index] = value;
    list->length++;

    return 1;
}

/**
 * 删除指定索引删除元素
 */
int removeAt(int index, PList list)
{
    if (index < 1 || index > list->length)
    {
        return 0;
    }

    //向前搬砖
    for (int i = index + 1; i < list->length; i++)
    {
        list->array[i - 1] = list->array[i];
    }

    list->length--;
    return 1;
}

/**
 * 释放列表
 * @param list 顺序表
 */
void disposeList(PList list)
{
    free(list);
}

/**
 * 打印列表
 * @param list 顺序表
 */
void printList(PList list)
{
    for (int i = 0; i < list->length; i++)
    {
        printf("%d,", list->array[i]);
    }
    printf("\n");
}
