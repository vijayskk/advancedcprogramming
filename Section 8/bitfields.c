#include <stdio.h>

struct packed
{
    unsigned int :3; // Padding
    unsigned int f1:1; // Just some variables 
    unsigned int f2:1;
    unsigned int f3:1;
    unsigned int type:8;
    unsigned int index:18;
}; // This uses 4bytes

struct packed2
{
    unsigned int f1;
    unsigned int f2;
    unsigned int f3;
    unsigned int type;
    unsigned int index;
}; // This uses 20 bytes 


int main(int argc, char const *argv[])
{
    printf("%lu",sizeof(struct packed)); // Out : 4

    struct packed p1;

    p1.f1 = 1;  // 0000 0000 0000 0000 0000 0000 0000 00010
    // These are now easy as just variables.
    return 0;
}
