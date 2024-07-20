#include <stdio.h>
#include <stdlib.h>

void sign_off()
{
    printf("Program is Quitting...\nGoodbye...\n");
}

void another_fn()
{
    printf("Dummy...\n");
}

int main(int argc, char const *argv[])
{
    atexit(sign_off);
    atexit(another_fn);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", i);
        if (i > 5)
        {
            abort();
        }
    }

    return 0;
}
