#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char s[] = "hello world";
    char find[] = "world";
    char *result = strstr(s, find);
    printf(result);
    return 0;
}