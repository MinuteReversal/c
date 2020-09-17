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

String substr(String s, int index, int length)
{
    String str = {"", 0};
    if ((index < 0) || (index > s.length))
    {
        printf("error\n");
        return str;
    }
    else if (s.length - index < length)
    {
        s.text[index] = '\0';
        s.length = index - 1;
        return s;
    }
    else
    {
        for (size_t i = index + length; i <= s.length; i++)
        {
            s.text[i - length] = s.text[i];
        }
        s.length = s.length - length;
        return s;
    }
}

int match(String s1, String s2)
{
    for (size_t i = 0; i < s1.length; i++)
    {
        int matchLength = 0;
        for (size_t j = 0; j < s2.length; j++)
        {
            if (s1.text[i + j] != s2.text[j])
            {
                break;
            }
            matchLength++;
        }

        if (matchLength == s2.length)
        {
            return 1;
        }
    }

    return -1;
}

String replace(String s1, String s2, int index, int length)
{
    String str;
    str = substr(s1, index, length);
    str = insert(str, s2, index);
    return str;
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

    String s3 = {"Beijing Shanghai China", 22};
    s = substr(s3, 8, 8);
    printf("%s\n", s.text);
    String m = {"Shanghai", 8};

    int r;
    r = match(s3, m);
    printf("%d\n", r);

    String s4 = {"You are a student.", 18};
    String s5 = {"teacher", 7};

    String s6 = replace(s4, s5, 10, 7);
    printf("%s\n", s6.text);
    return 0;
}