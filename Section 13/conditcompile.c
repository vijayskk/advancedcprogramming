#define LIMIT 10
#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; i++)
    {
        ;
        #ifdef DEBUG
        printf("%dth loop runned\n",i+1);
        #endif
    }
    printf("Loop Finished...\n");
    return 0;
}
