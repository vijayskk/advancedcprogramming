#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    FILE * fp = fopen("hello.txt","r");
    if (fp == NULL)
    {
        exit(1);
    }
    fflush(fp);
    
    fclose(fp);
    return 0;
}
