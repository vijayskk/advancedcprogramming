#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    here:
    printf("Select an option:\n\t1.Murder\n\t2.Suicide\n\n: ");
    int choice;
    scanf("%d",&choice);
    switch (choice) 
    {
    case 1:
        printf("Enter the target id to murder: ");
        pid_t pid;
        scanf("%d",&pid);
        if(kill(pid,SIGSTOP) == -1){
            printf("Operation failed. Target is immortal\nBye.");
        }else{
            printf("Target is killed\nBye.");
        }
        break;
    case 2:
        printf("Commiting suicide using SIGSTOP\nDead.\n");
        raise(SIGSTOP);
    default:
        printf("Select a valied option...");
        goto here;
        break;
    }
    return 0;
}

