#include <stdio.h>

#define PRINT(a, b)\
    printf("Value 1 : %d\n",a); \
    printf("Value 2 : %d\n",b);

int main(int argc, char const *argv[])
{
    PRINT(10,20)
    return 0;
}
