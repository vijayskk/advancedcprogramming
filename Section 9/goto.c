#include <stdio.h>

int main(int argc, char const *argv[])
{
    int index = 0;
    while (1)
    {
        printf("%d\n",index);
        if (index == 100)
        {
            goto exit;
        }
        index++;
    }
    exit:
        printf("The loop finished ");
        printf("\nExitting....");
    return 0;
}
