#include <math.h>
#include <stdlib.h>
#include <stdio.h>

extern void dectobin(int n,int length){
    long int result=0,i=0;
    while (n > 0)
    {
        result += (n%2) * pow(10,i);
        n = n/2;
        i++;
    }
    for (int j = 0; j < length - i; j++)
    {
        printf("0");
    }
    printf("%ld\n",result);
}
extern long int dectobinr(int n){
    long int result=0,i=0;
    while (n > 0)
    {
        result += (n%2) * pow(10,i);
        n = n/2;
        i++;
    }
    return result;
}