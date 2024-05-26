#include <stdio.h>
#include "functions.h"

void takeinput(char * text,int * loc);
int main(int argc, char const *argv[])
{
    int sum = 0;
    int n;
    takeinput("Enter the length: ",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int k;
        printf("Enter the %dth number: ",i);
        scanf("%d",&k);
        arr[i] = k;
    }
    printf("The array is : ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d",arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    printf("\nThe sum is : %d\n",sum);
    
    return 0;
}
