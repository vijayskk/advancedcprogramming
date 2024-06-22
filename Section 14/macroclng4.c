#include <stdio.h>

#define IS_UPPER(c,flag) if(c < 91 && c > 64 )\
     { flag = 1;}
#define IS_LOWER(c,flag) if(c < 91 && c > 64 )\
     { flag = 1;}

int main(int argc, char const *argv[])
{
    char c = 'X';
    int isUpper = 0;
    IS_UPPER(c,isUpper)
    if (isUpper == 1)
    {
        printf("Charecter is upper\n");
    }else{
        printf("Charecter is lower\n");
    }
    
    return 0;
}
