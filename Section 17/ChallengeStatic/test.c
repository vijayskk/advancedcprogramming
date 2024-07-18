#include "libstringfns.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("Length is : %d\n",lengthOfString("Vijay"));

    printf("count of v is : %d\n",countChars("Vijay",'i'));

    char st1[10] = "12Vijay21";
    char st2[10] = "12Vijay21";
    char dest[20];

    extractFromString(st1,2,5,dest);
    printf("%s\n",dest);


    return 0;
}
