#include <stdio.h>

void fnC()
{
    printf("fnC start");
    printf("fnC end");
}

void fnB()
{
    printf("fnB start");
    fnC();
    printf("fnB end");
}

void fnA()
{
    printf("fnA start");
    fnB();
    printf("fnA end");
}

int main(int argc, char const *argv[])
{
    fnA();
    return 0;
}