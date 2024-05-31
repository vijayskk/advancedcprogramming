#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int bintodec(long int n){
    int index = 0;
    int result = 0; 
    while (n != 0)
    {
        int c = n%10;
        if (c!=0 && c!=1)
        {
            printf("Bad input...\n");
            return 0;
        }
        result += pow(2,index) * c;
        index++;
        n = n/10;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    char *p;
    long int n;
    n = strtol(argv[1], &p, 10);
    printf("The decimal number is : %d\n",bintodec(n));
    return 0;
}
