#include <stdio.h>

void fun1(){
    printf("Inside f1...\n");
    for (int i = 0; i < 0xffff; i++)
    {
        ;
    }
}
void fun2(){
    printf("Inside f2...\n");
    for (int i = 0; i < 0xffff; i++)
    {
        ;
    }
}

int main(int argc, char const *argv[])
{
    printf("Inside main...\n");
    for (int i = 0; i < 0xffff; i++)
    {
        ;
    }
    fun1();
    fun2();
    return 0;

}
