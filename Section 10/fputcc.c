#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE * fp = fopen("hello.txt" , "w");
    for (char i = 'A'; i <= 'Z'; i++)
    {
        fputc(i,fp);
    }
    fclose(fp);
    return 0;
}
