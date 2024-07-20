#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    clock_t start,end;
    double cputime = 0.0;

    start = clock();
    for (int i = 0; i < 100000000; i++)
    {
        printf("");
    }
    end = clock();
    cputime = (double)(end - start)/CLOCKS_PER_SEC;
    printf("CPU took %f seconds.\n",cputime);
    return 0;
}
