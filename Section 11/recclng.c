#include <stdio.h>

int recme(int n){
    if (n == 1)
    {
        return 1;
    }
    return n + recme(n-1);
    
}

int main(int argc, char const *argv[])
{
    printf("%d\n",recme(5));
    return 0;
}
