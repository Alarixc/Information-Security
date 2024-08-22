#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#define LOCALHOST "127.0.0.1"
//arbitrary port chosen for communication
#define PORT 9000

int main(int argc, char const*argv[]){
    printf("Hi, I am client, communicating through PORT %d\n",PORT);

    int sock=0,valread;
    struct sockaddr_in serv_addr;
    char*hello="Hi server, I am client.";
    char buffer[1024]={0};
    //family,type,protocol (default)
    sock=socket(AF_INET,SOCK_STREAM,0);
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(PORT);

    //convert IP address from human readable form to binary
    inet_pton(AF_INET,LOCALHOST,&serv_addr.sin_addr);
    //connect it to the server
    connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

    //on successful connection, send a message to the server
    send(sock,hello,strlen(hello),0);

    //read stream recieved into buffer
    valread=read(sock,buffer,1024);
    printf("Received message: %s\n",buffer);
    return 0;

}