#include <stdio.h>

int main(int argc, char const *argv[])
{
    wchar_t *wt=L"hello world\n";
    wprintf(L"%ls\n", wt);
    return 0;
}