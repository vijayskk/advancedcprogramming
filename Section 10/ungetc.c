#include <stdio.h>

int main(int argc, char const *argv[])
{
    char ch = ' ';
    while ((ch = (char)getc(stdin)) == ' '  )
    {
        ungetc(ch,stdin); // skips and gives the next charecter to ch.
    }
    printf("Char is : %c",ch);
    return 0;
}
