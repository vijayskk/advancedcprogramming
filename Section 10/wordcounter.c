#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int count = 1;
    int chars = 0;
    char ch = '\0';

    if (argc == 1)
    {
        while (ch != '\n')
        {
            ch = getc(stdin);
            if (ch == ' ')
            {
                ch = getc(stdin);
                if (ch != ' ' && ch != '\n')
                {
                    ++count;
                }
                ungetc(ch, stdin);
            }else{
                chars++;
            }
        }
    }
    else
    {

        FILE *fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            printf("File not found\n");
            exit(0);
        }

        while (ch != EOF)
        {
            ch = getc(fp);
            if (ch == ' ' || ch == '\n')
            {
                ch = getc(fp);
                if (ch != ' ' && ch != EOF && ch != '\n')
                {
                    ++count;
                }
                ungetc(ch, fp);
            }else{
                chars++;
            }
        }
    }

    printf("\nTotal words: %d\nTotal number of chars: %d\n", count,chars);
    return 0;
}
