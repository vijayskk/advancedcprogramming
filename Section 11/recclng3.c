#include <stdio.h>
#include <string.h>

void recme(int n,char * string){
    if (n!=0)
    {
        printf("%c",string[n-1]);
        recme(n-1,string);
    }
}

int main(int argc, char const *argv[])
{
    char string[30] = "studytonight";
    int len = strlen(string);
    recme(len,string);
    return 0;
}
