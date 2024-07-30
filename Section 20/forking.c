#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

void childProcess(void);
void parentProcess(void);


int main(int argc, char const *argv[])
{
    pid_t parentid = getpid();
    pid_t pid;
    fork();
    pid = getpid();
    
    if (pid == parentid)
    {
        parentProcess();
    }else{
        childProcess();
    }
    return 0;
}

void childProcess(void){
    printf("This is child process....\n");
    for (int i = 0; i < 1000000; i++)
    {
        ;
    }
    printf("child process finished....\n");
}

void parentProcess(void){
    printf("This is parent process....\n");
    for (int i = 0; i < 1000000; i++)
    {
        ;
    }
    printf("parent process finished....\n");
}