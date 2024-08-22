#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#define PORT 9000

int main(int argc, char const*argv[])
{
    printf("Hi, I am server, communicating through PORT %d\n", PORT);
    int server_fd,new_socket,valread;
    struct sockaddr_in address;
    int opt=1;
    int addrlen=sizeof(address);
    char buffer[1024]={0};
    char *hello="Hello client, I am server.";

    //create socket descriptor
    server_fd=socket(AF_INET,SOCK_STREAM,0);
    
    //attach it to port
    setsockopt(server_fd,SOL_SOCKET,SO_REUSEADDR,SO_REUSEPORT,&opt,sizeof(opt));

    address.sin_family=AF_INET;
    address.sin_addr.s_addr=INADDR_ANY;
    address.sin_port=htons(PORT);
    //bind it to port
    bind(server_fd,(struct sockaddr*)&address,sizeof(address));
    //listen on the port
    listen(server_fd,3);

    new_socket=accept(server_fd,(struct sockaddr*)&address,(socklen_t*)&addrlen);

    //read stream recieved into buffer
    valread=read(new_socket,buffer,1024);
    printf("Recieved message: %s\n",buffer);

    //on successful connection, send a message to client
    send(new_socket,hello,strlen(hello),0);
    return 0;
    
}