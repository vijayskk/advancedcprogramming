#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 10;
    int * p = &a;
    int ** dp = &p;
    printf("Value of dp: %p\n",dp);
    printf("Value of p from dp: %p\n",*dp);
    printf("Value of p directly: %p\n",p);
    printf("Value of a from p: %d\n",*p);
    printf("Value of a : %d\n",a);

    printf("Value of a from dp: %d",**dp);
    return 0;
}
