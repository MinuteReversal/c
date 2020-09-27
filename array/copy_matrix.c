#include <stdio.h>
#include <malloc.h>

int main(int argc, char const *argv[])
{
    // define matrix
    double A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    // allocate memory
    double **A_ptr = (double **)malloc(sizeof(double *) * 3);
    for (int i = 0; i < 3; i++)
        A_ptr[i] = (double *)malloc(sizeof(double) * 3);

    // copy matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            A_ptr[i][j] = A[i][j];
            printf(" %f ", A_ptr[i][j]);
        }
        printf("\n");
    }
    return 0;
}