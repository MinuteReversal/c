/******************************************************************************
* fileName    : hash_direct_address.c 
* author      : 114233763@qq.com
* date        : 2020-10-08 09:08:39
* description : 直接定址法
***************************************************************************** */
#include <stdio.h>

typedef struct _ElementAge
{
    int age;
    int population;
} ElementAge, *PElementAge;

typedef struct _ElementYear
{
    int year;
    int population;
} ElementYear, *PElementYear;

int hashAge(int key)
{
    return key - 1;
}

PElementAge searchAge(int age, PElementAge list, int length)
{
    if (age > 0 && age < length)
    {
        return &list[hashAge(age)];
    }
    return NULL;
}

int hashYear(int key)
{
    return key - 1948;
}

PElementYear searchYear(int year, PElementYear list, int length)
{
    if (year > 0 && year < year + length)
    {
        return &list[hashYear(year)];
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    ElementAge listAge[] = {
        {.age = 1, .population = 3000},
        {.age = 2, .population = 2000},
        {.age = 3, .population = 1050},
        {.age = 4, .population = 1200},
        {.age = 5, .population = 1800},
    };
    PElementAge a = searchAge(3, listAge, sizeof(listAge) / sizeof(ElementAge));

    ElementYear listYear[] = {
        {.year = 1949, .population = 3000},
        {.year = 1950, .population = 2000},
        {.year = 1951, .population = 5000},
        {.year = 1952, .population = 6200},
        {.year = 1953, .population = 7000},
    };

    PElementYear y = searchYear(1949, listYear, sizeof(listAge) / sizeof(ElementYear));
    return 0;
}