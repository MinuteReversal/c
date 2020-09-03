#include <stdio.h>
#define MAX_LEN 100

typedef struct _SqList
{
    int array[MAX_LEN];
    int length;
} SqList, *PSqList;

/**
 * 在指定位置前插入一个元素
 * 返回值 0 为错误 1为正常
 */
int insertBefore(int index, int value, SqList *list)
{
    int length = list->length; //有元素的个数
    int *array = list->array;  //数组指针
    int i;
    //插入位置超过范围
    if (index > length || index < 1)
        return 0;

    //向后搬砖
    for (i = length; i >= index; i--)
        array[i + 1] = array[i];

    array[i + 1] = value;
    list->length++;

    return 1;
}

int delete (int index, SqList *list)
{
    int length = list->length;
    int *array = list->array;
    int i;
    if (index < 1 || index > length)
        return 0;

    //向前搬砖
    for (i = index + 1; i < length; i++)
    {
        array[i - 1] = array[i];
    }
    list->length--;
    return 1;
}

//打印数组
void printArray(SqList list)
{
    for (int i = 0; i < list.length; i++)
    {
        printf("%d,", list.array[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    SqList list = {
        .array = {0, 1, 2, 3, 4, 5, 6, 7, 8},
        .length = 8,
    };

    printArray(list);
    insertBefore(3, 9, &list);
    printArray(list);
    delete (4, &list);
    printArray(list);
    return 0;
}