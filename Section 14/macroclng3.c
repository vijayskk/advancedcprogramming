#include <stdio.h>
#define SQUARE(x) x*x
#define CUBE(x) x*x*x

int main(int argc, char const *argv[])
{
    int a = 3;
    printf("Square of %d is %d.\n",a,SQUARE(a));
    printf("Cube of %d is %d.\n",a,CUBE(a));
    return 0;
}
