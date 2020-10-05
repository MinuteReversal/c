#include <stdio.h>
#include <malloc.h>

typedef struct _Student
{
    int id;
    char *name;
} Student, *PStudent;

void printStudent(PStudent student)
{
    printf("id:%d,name:%s\n", student->id, student->name);
}

PStudent createStudent(int id, char *name)
{
    PStudent student = (PStudent)malloc(sizeof(Student));
    student->id = id;
    student->name = name;
    return student;
}

int main(int argc, char const *argv[])
{
    PStudent student1 = createStudent(1, "zhy");
    PStudent student2 = createStudent(2, "lily");
    PStudent student3 = createStudent(3, "lucy");
    printStudent(student1);
    printStudent(student2);
    printStudent(student3);
    return 0;
}