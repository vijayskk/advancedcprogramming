// sort using qsort
#define SIZE 5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(double * arr,int n);
void showArray(double * arr,int n);
int compare(const void * p1,const void * p2);
int main(int argc, char const *argv[])
{
    double array[SIZE];
    fillArray(array,SIZE);
    showArray(array,SIZE);
    qsort(array,SIZE,sizeof(double),compare);
    showArray(array,SIZE);
    return 0;
}

void fillArray(double * arr,int n){
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = ((double)rand() / RAND_MAX ) * 10;
    }
}

void showArray(double * arr,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%f\t",arr[i]);
    }
    printf("\n");
}

int compare(const void * p1,const void * p2){
    const double a = *(const double *)p1;
    const double b = *(const double *)p2;
    if (a > b)
    {
        return 1;
    }else{
        return -1;
    }
}