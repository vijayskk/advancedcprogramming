#include <stdio.h>

int main(int argc, char const *argv[])
{
    char name[] = "Vijay";
    for (int i = 0; i < sizeof(name) - 1; i++)
    {
        putc(name[i],stdout);
    }
    return 0;
}
