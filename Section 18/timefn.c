#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    time_t currtime;
    currtime = time(0);
    printf("%s",ctime(&currtime));//Sat Jul 20 16:30:36 2024
    return 0;
}
