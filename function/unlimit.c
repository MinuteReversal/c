#include <stdio.h>
#include <stdarg.h>

/**
 * n is total
 */
void fn1(char *first, ...)
{
    char *str;
    va_list list;
    str = first;
    va_start(list, first);
    do
    {
        puts(str);
        str = va_arg(list, char *);
    } while (str != NULL);
    va_end(list);
}

int main(int argc, char const *argv[])
{
    fn1("first", "second", "thrid", NULL);
    return 0;
}