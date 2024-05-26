#include <stdio.h>

int main(int argc, char const *argv[])
{
    const double pi = 3.14;
    const int nums[2] = {1, 2};
    typedef const int myvarname;
    const myvarname var = 10;
    const int *ptr;

    volatile double loc1;
    volatile double *ptr1;

    int * restrict ptr2; 
    int * restrict ptr3;
    // Cannot have same address
    return 0;
}
