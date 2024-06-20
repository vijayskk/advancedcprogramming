#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char chartoCheck = argv[1][0];
    char * buffer;
    size_t buffersize = 256;
    size_t charecters;
    buffer = (char *) malloc(buffersize * sizeof(char));

    FILE * fp = fopen(argv[2],"r");
    if (fp == NULL)
    {
        fprintf(stderr,"File Opening Failed..");
        exit(1);
    }
    charecters = 1;
    while (1)
    {
        charecters = getline(&buffer,&buffersize,fp);
        if (charecters != -1)
        {
            if (strchr(buffer,chartoCheck) != NULL)
            {
                printf("%s",buffer);
            }
            
        }else{
            break;
        }
        
    }
    

    return 0;
}
