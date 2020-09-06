#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[2][2] = {{1, 2}, {3, 4}};
    int(*p)[2] = a; //指向二维数组的指针
    int *pa = *a;   //普通指向整形的指针
    const size_t intSize = sizeof(int);

    printf("========(*(a+row)+colum)=========\n");
    printf("%d\n", *(*(p + 0) + 0));
    printf("%d\n", *(*(p + 0) + 1));
    printf("%d\n", *(*(p + 1) + 0));
    printf("%d\n", *(*(p + 1) + 1));
    printf("==========a[row]+column=======\n");
    printf("%d\n", *(p[0] + 0));
    printf("%d\n", *(p[0] + 1));
    printf("%d\n", *(p[1] + 0));
    printf("%d\n", *(p[1] + 1));
    printf("=========a[row]+column========\n");
    printf("%d\n", *(a[0] + 0));
    printf("%d\n", *(a[0] + 1));
    printf("%d\n", *(a[1] + 0));
    printf("%d\n", *(a[1] + 1));
    printf("=========(*(a+row)+column)========\n");
    printf("%d\n", *(*(a + 0) + 0));
    printf("%d\n", *(*(a + 0) + 1));
    printf("%d\n", *(*(a + 1) + 0));
    printf("%d\n", *(*(a + 1) + 1));
    printf("==========(a+n),n=0,1,2,3...=======\n");
    printf("%d\n", *(pa + 0));
    printf("%d\n", *(pa + 1));
    printf("%d\n", *(pa + 2));
    printf("%d\n", *(pa + 4));
    printf("=========i*m+j;//m is columns count=====\n");
    printf("%d\n", *(pa + 0 * 2 + 0));
    printf("%d\n", *(pa + 0 * 2 + 1));
    printf("%d\n", *(pa + 1 * 2 + 0));
    printf("%d\n", *(pa + 1 * 2 + 1));
    return 0;
}