#include <stdio.h>

int main(int argc, char const *argv[])
{
    void * vp;
    int a = 10;
    vp = &a;
    printf("%p\n",vp);
    // To get the value,
    printf("%d\n",*(int *)vp);

    float b = 10.5;
    vp = &b;
    printf("%p\n",vp);
    // To get the value,
    printf("%f\n",*(float *)vp);
    return 0;
}
