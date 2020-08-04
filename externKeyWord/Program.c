#include "stdio.h"

extern int num;
extern void func();
int main(int argc, char *argv[], char *envp[])
{

    printf("%d\n", num);
    func();

    return 0;
}