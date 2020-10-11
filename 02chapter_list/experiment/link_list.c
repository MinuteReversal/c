#include <stdio.h>
#include <malloc.h>
#define MAX_LEN 20

typedef struct _SeqList
{
    /**
     * 数据集
     */
    int datas[MAX_LEN];
    /**
     * 列表长度
     */
    int length;
} SeqList, *PSeqList;

/**
 * 创建一个顺序表
 * @return 表
 */
PSeqList createSeqList()
{
    return (PSeqList)malloc(sizeof(SeqList));
}

/**
 * 初始化顺序表，给前十项赋默认值 
 * @return 表
 */
PSeqList initList()
{
    PSeqList list = createSeqList();
    int n = 10;
    for (size_t i = 0; i < n; i++)
    {
        list->datas[i] = i + 1;
    }
    list->length = n;
    return list;
}

/**
 * 将表一的内容复制到表二中
 * @return 无
 */
void copy(PSeqList list1, PSeqList list2)
{
    for (size_t i = 0; i < list1->length; i++)
    {
        list2->datas[i] = list1->datas[i];
    }
    list2->length = list1->length;
}

int main(int argc, char const *argv[])
{
    PSeqList list = initList();       //创建并初始化表
    PSeqList list2 = createSeqList(); //创建表
    copy(list, list2);                //复制
    return 0;
}