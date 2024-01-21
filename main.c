#include <stdio.h>
#include "functions.h"


int multip = 10; // This is a global variable 

void printmult(){
    printf("The Multiplier is %d\n",multip);
}

int main(int argc, char const *argv[])
{
    int a = 10;
    int pred = myfunc(a);
    printf("%d\n",pred * multip);
    printmult();
    return 0;
}


