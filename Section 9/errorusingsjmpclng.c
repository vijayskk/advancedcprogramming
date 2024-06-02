#define NOT_FOUND 404
#define BAD_REQUEST 304
#define SERVER_DOWN 504

#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf errbuf;

void function1()
{
    // A not found error occures here...
    longjmp(errbuf, NOT_FOUND);
}

void function2()
{
    // A bad request error occures here...
    longjmp(errbuf, BAD_REQUEST);
}

void function3()
{
    // A server error occures here...
    longjmp(errbuf, SERVER_DOWN);
}

void handleError()
{
    switch (setjmp(errbuf))
    {
    case NOT_FOUND:
        printf("\nThe webpage you looking not found...");
        exit(0);
        break;

    case BAD_REQUEST:
        printf("\nBad request found...");
        exit(0);
        break;

    case SERVER_DOWN:
        printf("\nThe server is down...");
        exit(0);
        break;
    case 0:
        break;
    default:
        printf("\nUndiscovered error occured...");
        exit(0);
        break;
    }
}

int main(int argc, char const *argv[])
{

    handleError();

    printf("Main function executes");

    function1();
    function2();
    function3();

    return 0;
}
