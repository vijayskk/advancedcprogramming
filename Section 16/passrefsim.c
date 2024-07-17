#include <stdio.h>
#include <stdlib.h>

void myfun(int *p)
{
    int a = 5;
    p = &a;
} // This function cannot affect the value of p globally.

void myFunD(int ** dp)
{
    int b = 5;
    *dp = &b;
} // This can assign the address of local variable b to a pointer and we can access it from higher scope.

int main(int argc, char const *argv[])
{
    int *ptr = (int *)malloc(sizeof(int));
    *ptr = 10;
    printf("Value of ptr data is: %d\n", *ptr);
    myfun(ptr);
    printf("Value of ptr data is: %d\n", *ptr); // Same Output

    int ** dp = &ptr;
    myFunD(dp);
    printf("Value of ptr data is: %d\n", *ptr); // The value will be changed.
    return 0;
}
