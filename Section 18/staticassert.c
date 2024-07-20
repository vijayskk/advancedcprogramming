#include <stdio.h>
#include <assert.h>

#ifndef BATT
#define BATT 10
#endif

int main(int argc, char const *argv[])
{
    static_assert(BATT > 25,"Battery low.Compiling aborted...");
    return 0;
}
