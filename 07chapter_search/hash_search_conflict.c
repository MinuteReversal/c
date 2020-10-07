#include <stdio.h>
#include "../02chapter_list/sequence_list.h"
#define MAX_LEN 50

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

int main(int argc, char const *argv[])
{
    char *BEIJING = "BEIJING";
    char *SHANXI = "SHANXI";
    char *SHANGHAI = "SHANGHAI";
    char *SHANDONG = "SHANDONG";
    char *HENAN = "HENAN";
    char *SICHUAN = "SICHUAN";

    int index1 = hash1(SHANXI, 6);
    int index2 = hash1(SHANGHAI, 8);
    int index3 = hash1(SHANDONG, 8);

    int result1 = hash2(SHANXI, 6);
    int result2 = hash2(SHANGHAI, 8);
    int result3 = hash2(SHANDONG, 8);
    return 0;
}