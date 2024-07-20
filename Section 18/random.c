#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateInRange(int from,int to){
    srand(time(0));
    from--;
    return rand() % (to - from) + from + 1;
}

int main(int argc, char const *argv[])
{
    // if (argc > 1)
    // {
    //     srand(atoi(argv[1]));
    // }else{
    //     srand(1);
    // }
    for (int i = 0; i < 100; i++)
    {
        printf("%d\n",generateInRange(3,5));
    }
    return 0;
}

