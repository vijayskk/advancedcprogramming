#include <stdio.h>

int main(int argc, char const *argv[])
{
    char ch = ' ';
    int firstTime = 1;
    while (1)
    {
        ch = getc(stdin);
        if (firstTime == 1)
        {
            printf("You said : ");
            firstTime = 0;
        }
        printf("%c", ch);
        if (ch == '\n')
        {
            firstTime = 1;
        }
    }
    return 0;
}
