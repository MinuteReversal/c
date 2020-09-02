#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    time_t rawTime;
    struct tm *timeInfo;

    time(&rawTime);
    timeInfo = localtime(&rawTime);
    printf("Current local time and date: %s", asctime(timeInfo));

    return 0;
}