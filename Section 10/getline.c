#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char * buffer = NULL;
    char buffer[32];
    size_t bufsize = 32;
    size_t charecters;

    buffer = (char *) malloc(bufsize * sizeof(char));

    if (buffer == NULL)
    {
        exit(1);
    }

    printf("Type Something: ");
    charecters = getline(&buffer,&bufsize,stdin);
    printf("You typed: %s\nNumber of charecters read: %zu \n",buffer,charecters - 1);
    

    return 0;
}
