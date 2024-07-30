#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    const pid_t parent = getpid();


    pid_t n0 = fork();
    pid_t n1 = fork();
    pid_t n2 = fork();

    printf("Process id : %d\n",getpid());
    if (n1>0 && n2>0)
    {
        printf("Parent\n");;
    }else if(n1 == 0 && n2 > 0){
        printf("First\n");
    }else if(n1 > 0 && n2 == 0){
        printf("Second\n");
    }
    else{
        printf("Third\n");
    }
    
    return 0;
}
