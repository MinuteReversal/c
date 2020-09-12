#include <stdio.h>
typedef struct _Student
{
    int id;
    char name[20];

} Student, *PStudent;

int main(int argc, char const *argv[])
{
    Student stu1 = {id : 1, name : "zhy"};
    Student stu2 = {id : 2, name : "ReversalMinute"};

    printf("id:%d,name:%s\n", stu1.id, stu1.name);
    printf("id:%d,name:%s\n", stu2.id, stu2.name);
    return 0;
}