#include <stdio.h>
#include <string.h>

struct Student
{
    int id;
    char name[20];
    int no;
} student;

int main(int argc, char const *argv[])
{
    student.id = 0;
    student.name[0] = 'z';
    student.name[1] = 'h';
    student.name[2] = 'y';
    student.no = 123;

    printf("id:%d,name:%s,no:%d\n", student.id, student.name, student.no);
    return 0;
}