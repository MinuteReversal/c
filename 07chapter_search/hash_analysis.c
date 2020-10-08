/******************************************************************************
* fileName    : hash_analysis.c 
* author      : 114233763@qq.com
* date        : 2020-10-08 09:36:46
* description : 数字分析法,取分布均匀的位做键
***************************************************************************** */
#include <stdio.h>
#include <malloc.h>

char *hash(char *value)
{
    char *key = (char *)malloc(3 * sizeof(char));
    key[0] = value[2]; //第三位
    key[1] = value[4]; //第五位
    key[2] = '\0';
    return key;
}

int main(int argc, char const *argv[])
{
    char *keys[] = {
        "6151141",
        "6103274",
        "6111034",
        "6138299",
        "6120874",
        "6195394",
        "6170924",
        "6140637",
    };

    for (size_t i = 0; i < sizeof(keys) / sizeof(char *); i++)
    {
        printf("%s\n", hash(keys[i]));
    }

    return 0;
}