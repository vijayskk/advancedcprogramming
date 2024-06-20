#include <stdio.h>

void recme(int a,int b,int n){
    if (n!=0)
    {
        if (a%n == 0 && b%n == 0)
        {
            printf("\nGCD is %d\n\n",n);
            n = 1;
        }
        
        recme(a,b,n-1);
    }
}

int main(int argc, char const *argv[])
{
    int a,b;
    printf("Enter the numbers: ");
    scanf("%d,%d",&a,&b);
    if (a >= b)  
    {
        recme(a,b,b);
    }else{
        recme(a,b,a);
    }
    return 0;
}
