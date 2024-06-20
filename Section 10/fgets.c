#define MAXLEN 30
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[MAXLEN];
    fgets(str,MAXLEN,stdin);
    printf("%s\n",str);
    return 0;
}
