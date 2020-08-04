#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int result = strcmp("a", "a");
    printf("%d\n", result);//相同输出0
    return 0;
}