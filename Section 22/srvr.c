#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    short skt;
    skt = socket(AF_INET,SOCK_STREAM,0);

    if (skt == -1)
    {
        printf("Socket creation failed...\n");
    }
    

    int port = 12345;
    struct sockaddr_in remote = {0};
    remote.sin_family = AF_INET;
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(port);
    int ret = bind(skt,(struct sockaddr_in *)&remote,sizeof(remote));

    if (ret == -1)
    {
        printf("bind creation failed...\n");
    }

    listen(skt,3);

    int sock_desc = 0,sock = 0,clientlen = 0;
    struct sockaddr_in client; 
    char client_message[100] = {0};
    char message[100] = {0}; 
    const char * pMessage = "hello";
    while(1){
        printf("Waiting for connection....\n");
        clientlen = sizeof(struct sockaddr_in);

        sock = accept(sock_desc,(struct sockaddr_in *)&client,(socklen_t *)&clientlen);
        
        if (sock < 0)
        {
            printf("Accept failed...");
        }
        
        memset(client_message,'\0',sizeof(client_message));
        memset(message,'\0',sizeof(message));
        
    }
}
