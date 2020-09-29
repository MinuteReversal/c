#include <stdio.h>

int main(int argc, char const *argv[])
{
    char *s = "hello";
    char *s1 = "world";
    char s3[] = {"hello"};
    char s4[] = "world";
    printf("%s %s %s %s\n", s, s1, s3, s4);
    return 0;
}