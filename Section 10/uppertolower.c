#include <stdio.h>
#include <stdlib.h>


int isUpper(char ch){
    if (ch >= 'A' && ch <= 'Z')
    {
        return 1;
    }else{
        return 0;
    }
}

char toUpper(char ch){
    return ch - 32;
}

char toLower(char ch){
    return ch + 32;
}


int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        printf("Missing arguments...\n");
        exit(0);
    }
    

    FILE * ip;
    FILE * op;
    if ((ip=fopen(argv[1],"r")) != NULL)
    {
        op = fopen(argv[2],"w");
    }else{
        printf("File %s not found...\n",argv[1]);
        exit(0);
    }
    char ch = '\0';
    while ( (ch = fgetc(ip)) != EOF)
    {
        if ( (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            if (isUpper(ch) == 1 )
            {
                ch = toLower(ch); 
            }else{
                ch = toUpper(ch);
            }
        }
        fputc(ch,op);
        printf("%d\n",ch);
    }
    fclose(ip);
    fclose(op);

    return 0;
}
