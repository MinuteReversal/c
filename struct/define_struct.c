#include <stdio.h>
typedef struct _Student
{
    int id;
    char *name;
} Student, *PStudent;

int main(int argc, char const *argv[])
{
    Student student = {
        id : 1,
        name : "Zhang yu"
    };

    PStudent pstudent = &student;

    printf("id:%d,name:%s\n", student.id, student.name);
    printf("id:%d,name:%s\n", pstudent->id, pstudent->name);
    return 0;
}