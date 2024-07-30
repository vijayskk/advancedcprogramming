#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    alarm(5);
    while (1)
    {
        ;
    }
        
    return 0;
}
