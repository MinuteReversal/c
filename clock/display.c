/**
 * http://www.cplusplus.com/reference/ctime/strftime/
 */
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, 80, "Now it's %Y-%m-%d %H:%M:%S.", timeinfo);
    puts(buffer);
    return 0;
}