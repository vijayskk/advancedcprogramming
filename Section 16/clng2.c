// In this challenge we have to access a 
// locally declared variable in a function
// from the main function and change its value.
// WitchCraft!!!

#include <stdio.h>
#include <stdlib.h>

void funcone(int ** dp){
    int secreteval = 10;
    printf("funcone says: %p holds %d value!!!\n",&secreteval,secreteval);
    *dp = &secreteval; 
}

int main(int argc, char const *argv[])
{
    int ** dp = (int **) malloc(sizeof(int **));
    funcone(dp);
    printf("main says: %p holds %d value!!!\n",*dp,**dp);
    **dp = 100;
    printf("main says: %p holds %d value!!!\n",*dp,**dp);
    return 0;
}
