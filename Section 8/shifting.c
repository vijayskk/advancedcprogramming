#include <stdio.h>
#include "functions.h"

int main(int argc, char const *argv[])
{
    for (int j = 0; j < 100; j++)
    {
        int a = 8; // 0000 0000 0000 0000 0000 0000 0000 1000
        for (int i = 0; i < 4; i++)
        {
            dectobin(a, 4);
            a = a >> 1;
        }
    }

    return 0;
}
