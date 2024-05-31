#include <stdio.h>
#include "functions.h"
#include <math.h>
int main(int argc, char const *argv[])
{
    char *p;
    int n;
    int a = strtol(argv[1], &p, 10);
    int b = strtol(argv[2], &p, 10);
    printf("\nThe complement of %d (%ld) : -%ld",a,dectobinr(a),dectobinr(abs(~a)));
    printf("\n\nThe complement of %d (%ld) : -%ld",b,dectobinr(b),dectobinr(abs(~b)));
    
    printf("\n\nResult of bitwise AND of %d (%ld) and %d (%ld) : %ld",a,dectobinr(a),b,dectobinr(b),dectobinr(a&b));
    printf("\n\nResult of bitwise OR of %d (%ld) and %d (%ld) : %ld",a,dectobinr(a),b,dectobinr(b),dectobinr(a|b));
    printf("\n\nResult of bitwise XOR of %d (%ld) and %d (%ld) : %ld",a,dectobinr(a),b,dectobinr(b),dectobinr(a^b));
    
    printf("\n\n");
    return 0;
}
