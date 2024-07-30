#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handleer(int signal){
    printf("Signal got...");
}

int main(int argc, char const *argv[])
{
    printf("Program ran on PID %d\nParent: PID %d\n",getpid(),getppid());
    struct sigaction new_action;
    new_action.sa_flags = 0;
    new_action.sa_handler = handleer;
    sigemptyset(&new_action.sa_mask);

    sigaction(SIGINT,NULL,&new_action);

    while(1){;}
    return 0;
}
