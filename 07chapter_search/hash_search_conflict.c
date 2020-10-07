#include <stdio.h>
#include "../02chapter_list/sequence_list.h"
#define MAX_LEN 50

/**
 * 省份
 */
typedef struct _Provice
{
    char *key;
    char *name;
} Provice, *PProvice;

/**
 * 散列算法1
 * @param key 键
 * @return index
 */
int hash1(char key[], int length)
{
    int firstChar = key[0] - 65;
    return firstChar;
}

/**
 * 散列算法2
 * @param key 键
 * @return index
 */
int hash2(char *key, int length)
{
    int firstChar = key[0] - 65;
    int lastChar = key[length - 1] - 65;
    int index = firstChar + lastChar;
    if (index > 30)
    {
        index - 10;
    }
    return index;
}

/**
 * 查找
 * @param key 键
 * @param array 数组
 * @param hashType 散列算法类型
 * @return index
 */
int search(char *key, int keyLength, int hashType)
{
    int index = -1;
    if (1 == hashType)
    {
        index = hash1(key, keyLength);
    }
    else if (2 == hashType)
    {
        index = hash2(key, keyLength);
    }

    return index;
}

int main(int argc, char const *argv[])
{

    Provice provices[] = {
        {.key = "BEIJING", .name = "北京"},
        {.key = "SHANXI", .name = "山西"},
        {.key = "SHANGHAI", .name = "上海"},
        {.key = "SHANDONG", .name = "山东"},
        {.key = "HENAN", .name = "河南"},
        {.key = "SICHUAN", .name = "四川"},
    };

    int index1 = search("SHANXI", 6, 1);
    int index2 = search("SHANGHAI", 8, 1);
    int index3 = search("SHANDONG", 8, 1);

    int result1 = search("SHANXI", 6, 2);
    int result2 = search("SHANGHAI", 8, 2);
    int result3 = search("SHANDONG", 8, 2);
    return 0;
}