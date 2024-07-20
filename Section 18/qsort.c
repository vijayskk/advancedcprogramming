#include <stdio.h>
#include <stdlib.h>

int compare(const void *, const void *);

int main(int argc, char const *argv[])
{
    int data[5] = {12, 43, 23, 12, 1};

    for (int i = 0; i < 5; i++)
    {
        printf("%d  ", data[i]);
    }
    printf("\n");

    qsort(data, 5, sizeof(int), compare);

    for (int i = 0; i < 5; i++)
    {
        printf("%d  ", data[i]);
    }
    printf("\n");

    return 0;
}

int compare(const void *pa, const void *pb)
{
    const int a = *(const int *)pa;
    const int b = *(const int *)pb;
    return b - a; // a-b for ascending
};