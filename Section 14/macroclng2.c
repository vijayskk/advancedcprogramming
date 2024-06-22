#include <stdio.h>
#define SUM(a,b) a+b

int main(int argc, char const *argv[])
{
    int a = 10,b = 20;
    printf("Addition result of %d + %d is %d.\n",a,b,SUM(a,b));
    return 0;
}
