#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void signalrecieved(int signal){
    printf("SIGINT recieved...\n");
}

int main(int argc, char const *argv[])
{
    printf("Program ran on PID %d\nParent: PID %d\n",getpid(),getppid());
    void (*sigreturn) (int);
    sigreturn = signal(SIGINT,signalrecieved);

    if (sigreturn == SIG_ERR)
    {
        perror("Signal error...\n");
    }
    
    while(1){;}
    
    return 0;
}
