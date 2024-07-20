#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    time_t currtime = time(0);
    struct tm * localdata = localtime(&currtime);
    printf("%s\n",asctime(localdata));
    return 0;
}
