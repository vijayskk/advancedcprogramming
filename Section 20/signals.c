#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char const *argv[])
{
    here:
    printf("Select an option:\n\t1.Murder\n\t2.Suicide\n\n: ");
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        ;
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

