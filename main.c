#include <stdio.h>
#include "functions.h"


int i = 10;
void updatei(int a);

int main(int argc, char const *argv[])
{
    printf("%d\n",i);
    updatei(100);
    printf("%d\n",i);
    return 0;
}


