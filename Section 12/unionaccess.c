#include <stdio.h>

union mixed
{
    int a;
    float b;
    char c;
};

int main(int argc, char const *argv[])
{
    union mixed x = {10}; //  assigns as the first member
    printf("%d\n", x.a);
    x.b = 12.5;
    printf("%f\n", x.b);

    union mixed y = {.b = 24.1};
    printf("%d\n", y.a); // Undefined behaviour
    printf("%f\n", y.b);

    union mixed *z = &y;
    printf("%f\n", z->b);
    return 0;
}
