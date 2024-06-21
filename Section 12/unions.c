#include <stdio.h>

union Data
{
    int a;
    float b;
    char c[20];
};
struct Person
{
    char name[30];
    int age;
    union Data data;
    union
    {
        int isDead;
        char occupation[20];
    };
};

struct
{
    char *name;
    enum symbolType;
    union
    {
        int i;
        float f;
        char c;
    } data;
} table[10];

int main(int argc, char const *argv[])
{
    union Data data1, data2, *data3;
    struct Person p1;
    printf("%ld\n", sizeof(data1)); // OUT: 20
    printf("%ld\n", sizeof(p1));    // OUT: 20
    return 0;
}
