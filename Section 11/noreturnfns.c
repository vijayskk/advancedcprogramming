#include <stdio.h>
#include <stdnoreturn.h>
#include <stdlib.h>

noreturn void exitfrom(char * process,int code);
 
void exitfrom(char * process,int code){
    printf("Exitting from %s...",process);
    exit(code);
}

int main(int argc, char const *argv[])
{
    exitfrom("Download",1);
    return 0;
}
