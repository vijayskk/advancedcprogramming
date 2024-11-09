#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <arpa/inet.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    struct servent * ser = getservbyname("ssh","TCP");
    printf("%d",ser->s_port);
    return 0;
}
