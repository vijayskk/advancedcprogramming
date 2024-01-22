#include <stdio.h>
#include "functions.h"


extern void countNow(void);
extern void sayCount(void);

int main(int argc, char const *argv[])
{
    sayCount();
    countNow();
    countNow();
    sayCount();
}


