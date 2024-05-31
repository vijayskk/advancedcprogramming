#include <stdio.h>
#include <math.h>
#include "functions.h"

int main(int argc, char const *argv[])
{
    int a = 0;
    for (int i = 0; i < 8; i++)
    {
        int temp;
        printf("question? (1 = Yes,0 = No) : ");
        scanf("%d", &temp);
        if (temp == 1)
        {
            a = a | (int)pow(2, i);
        }
    }
    printf("\nThe integer value is: %d\nBinary number is: ",a);
    dectobin(a, 8);
    return 0;
}
