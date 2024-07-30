#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("Program ran on PID %d\nParent: PID %d\n",getpid(),getppid());
    return 0;
}
