#include <stdio.h>
#include <malloc.h>
#define MAX_LEN 32

typedef struct _String
{
    char text[MAX_LEN];
    int length;
} String, *PString;

String connect(String s1, String s2)
{
    String s;
    if (s1.length + s2.length <= MAX_LEN)
    {
        for (size_t i = 0; i < s1.length; i++)
        {
            s.text[i] = s1.text[i];
        }
        for (size_t i = 0; i < s2.length; i++)
        {
            s.text[s1.length + i] = s2.text[i];
        }
        s.text[s1.length + s2.length] = '\0';
        s.length = s1.length + s2.length;
    }
    else
    {
        s.length = 0;
    }
    return s;
}

int isEqual(String s1, String s2)
{
    if (s1.length != s2.length)
        return 0;

    for (size_t i = 0; i < s1.length; i++)
    {
        if (s1.text[i] != s2.text[i])
        {
            return 0;
        }
    }
    return 1;
}

/**
 * 取子串
 */
String substring(String s, int index, int length)
{
    String sub = {"", 0};
    if (index < s.length && length < index + s.length)
    {
        for (size_t i = 0; i < length; i++)
        {
            sub.text[i] = s.text[index + i];
        }
    }
    return sub;
}

/**
* 插入字串
* @param s1 
* @param s2
* @param index 插入的位置
* @return 字符串
*/
String insert(String s1, String s2, int index)
{
    String str = {"", 0};
    if (s1.length + s2.length >= MAX_LEN || index > s1.length + 1 || index < 0)
    {
        printf("overflow \n");
        return str;
    }

    for (size_t i = 0; i < index; i++)
    {
        str.text[i] = s1.text[i];
    }
    //先搬后半部分
    for (size_t i = s1.length; i >= index; i--)
    {
        str.text[i + s2.length - 1] = s1.text[i - 1];
    }
    //后搬前半部分
    for (size_t i = 0; i < s2.length; i++)
    {
        str.text[i + index] = s2.text[i];
    }
    str.length = s1.length + s2.length;
    str.text[s1.length + s2.length] = '\0';

    return str;
}

String delete (String s, int index, int length)
{
}

int main(int argc, char const *argv[])
{
    String s1 = {"Beijing", 7}, s2 = {"China", 5};
    String s = connect(s1, s2);
    printf("%s\n%d\n", s.text, s.length);

    int same = isEqual(s1, s2);
    printf("s1 eqaul s2  %d\n", same);

    String sub = substring(s1, 0, 3);
    printf("%s\n", sub.text);

    String inserted = insert(s1, s2, 3);
    printf("%s\n", inserted.text);

    return 0;
}