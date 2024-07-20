#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

void printArr(int * original,int * result){
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t",original[i]);
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t",result[i]);
    }
    printf("\n\n");
}

int main(int argc, char const *argv[])
{
    int values[SIZE] = {1,2,3,4,5};
    int target[SIZE];
    memmove(target,values,SIZE * sizeof(int));

    printArr(values,target);

    return 0;
}
