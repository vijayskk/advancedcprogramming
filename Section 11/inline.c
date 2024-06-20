#include <stdio.h>

int addNumbers(int a,int b){
    return a+b;
}

inline int addNumbers(int a,int b);

int main(int argc, char const *argv[])
{
    printf("%d",addNumbers(10,20));
    return 0;
}
