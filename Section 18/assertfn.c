#define NDEBUG
// #undef NDEBUG will turn assertions on
#include <stdio.h>
#include <assert.h>
#ifndef BATT
#define BATT 10
#endif

int main(int argc, char const *argv[])
{
    assert(BATT > 25);
    printf("Working...\n");
    return 0;
}
