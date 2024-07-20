// Generate 50 random numbers b/w -0.5 and 0.5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 50; i++)
    {
        int random = rand();
        printf("%f\n",((float)random/RAND_MAX) - 0.5);
    }
    
    return 0;
}
