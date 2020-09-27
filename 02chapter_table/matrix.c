#include <stdio.h>
#include "matrix.h"

int main(int argc, char const *argv[])
{
    PMatrix m = initMatix(5, 5);
    printMatrix(m);
    disposeMatrix(m);
    return 0;
}