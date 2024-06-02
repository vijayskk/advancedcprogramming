#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 5, i = 0;
    printf("Enter the number of lines: ");
    scanf("%d",&n);

    int m = 0;
    while (1)
    {
        printf("  ");
        if (m > n/2)
        {
            goto exit5;
        }
        m++;
    }

    exit5:printf("*\n");
    while (1)
    {

        int k = 0;
        while (1)
        {
            printf(" ");
            if (k >= (n - i))
            {
                goto exit3;
            }
            k++;
        }
    exit3:
        printf("*");
        int j = 0;
        while (1)
        {
            printf("   ");
            if (j >= i)
            {
                goto exit2;
            }
            j++;
        }
    exit2:
        printf("*\n");
        i++;
        if (i >= n)
        {
            goto exit1;
        }
    }
exit1:printf("");
    int j = 0;
    while (1)
    {
        printf(" *  ");
        if (j >= n)
        {
            goto exit4;
        }
        j++;
    }
exit4:printf("\n");
    return 0;
}
