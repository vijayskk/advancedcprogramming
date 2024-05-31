#include <stdio.h>
#include "functions.h"
int main(int argc, char const *argv[])
{
    // int mask = 1;
    // int num = 129;
    // int result = num & mask;
    // printf("%ld masked by %ld is %ld",dectobinr(num),dectobinr(mask), dectobinr(result));
    
    // int mask = 1;
    // int num = 64;
    // int result = num | mask;
    // printf("%ld masked by %ld is %ld",dectobinr(num),dectobinr(mask), dectobinr(result));
    
    int mask = 1;
    int num = 255;
    int result = num & (~mask);
    printf("%ld masked by %ld is %ld",dectobinr(num),dectobinr(mask), dectobinr(result));
    return 0; 
}
