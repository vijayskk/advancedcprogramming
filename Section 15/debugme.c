#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef DEBON
#warning DEBUGGER IS ON 
#define DEBUGME(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#else
#define DEBUGME(fmt,...)
#endif

int main(int argc, char const *argv[])
{
    char name[30];
    scanf("%s",name);
    for (int i = 0; i < strlen(name); i++)
    {
        DEBUGME("%c -> %c\n",name[i],name[i] + 1);
        name[i] += 1;
    }
    printf("%s\n",name);
    return 0;
}
