#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long int dectobin(int n){
    long int result=0,i=0;
    while (n > 0)
    {
        result += (n%2) * pow(10,i);
        n = n/2;
        i++;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    char *p;
    int n;
    n = strtol(argv[1], &p, 10);
    printf("The decimal number is : %ld\n",dectobin(n));
    return 0;
}
