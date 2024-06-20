#define FILENAME "hello.txt"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE * fp = NULL;
    fp = fopen(FILENAME,"rw");
    if (fp == NULL)
    {
        printf("Opening %s failed...",FILENAME);\
        exit(0);
    }else{
        printf("File %s Opened....\n\n",FILENAME);

    }
    
    char ch = ' ';
    while (ch = fgetc(fp),ch != EOF)
    {
        printf("%c", ch);
    }
    fclose(fp);
    printf("\n\nFile %s Closed....\n",FILENAME);
    return 0;
}
