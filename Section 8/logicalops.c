#include <stdio.h>

int main(int argc, char const *argv[])
{

    long int a = 154;
    long int b = 100;
    long int c = 12;
    printf("%ld",~(a));
    printf("%ld",(a & b));
    printf("%ld",(a | b));
    printf("%ld",(b ^ c));
    printf("\n%ld",(b & ~(b)));
    return 0;
}
