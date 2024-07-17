#include <stdio.h>


int add(int a,int b){return a+b;};
int sub(int a,int b){return a-b;};
int mul(int a,int b){return a*b;};
int div(int a,int b){return b/a;};

int main(int argc, char const *argv[])
{
    int(*pfuncs[])(int,int) = {add,sub,mul,div};
    int choice;
    printf("Enter Your Choise:\n\t1.Add\n\t2.Subtract\n\t3.Multiply\n\t4.Divide\n: ");
    scanf("%d",&choice);

    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[10] = {11,12,13,14,15,16,17,18,19,20};
    printf("\nAnswers are:\n\t");
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t",pfuncs[choice-1](arr1[i],arr2[i]));
    }
    printf("\n");
    return 0;
}
