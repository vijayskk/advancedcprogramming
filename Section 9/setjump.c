#include <stdio.h>
#include <setjmp.h> // This must be added
#include <stdlib.h>

jmp_buf buf;

void myFunction(){
    printf("At myFunction\n");

    longjmp(buf,40); // This jumps to the main function to the saved process and returns 40.

    printf("This will not be printed");
}

int main(int argc, char const *argv[])
{
    int i = setjmp(buf); // This creates a process and saves it
    printf("i = %d\n",i);

    if (i > 0)
    {
        exit(0); // This will run if it longjumped.
    }
    
    myFunction();
    

    printf("This will not print."); // This will not print
    return 0;
}