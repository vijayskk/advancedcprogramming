#include <stdio.h>

int main(int argc, char const *argv[])
{
    char string[30] = "Hello Vijay...";

    FILE * fp = fopen("output.txt","w");
    puts(string);
    if (fp !=  NULL)
    {
        fputs(string,fp);
    }
    
    return 0;
}
