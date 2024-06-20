#include <stdio.h>

int main(int argc, char const *argv[])
{
    char string[100];
    sprintf(string,"\n   \033[4mNAME CARD\033[0m\n\n Name: %s\n Age: %s\n\n",argv[1],argv[2]);
    puts(string);
    return 0;
}
