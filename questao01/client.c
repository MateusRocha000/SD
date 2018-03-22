#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE     (1000)

int main(int narg, char *varg[])
{
    int socketfd;
    struct sockaddr_in server_addr;
    int port = atoi(varg[2]); //convert a string to an integer
    int recv_len, sent_len;
    char buf[BUF_SIZE];

    printf("Connecting to %s:%d\n", varg[1], port);

    // create the socket if possible
    if ((socketfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("unable to create socket");
        return -1;
    }

    // configure the server address for the socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(varg[1]);

    // connect to the server via the socket created above
    if (connect(socketfd,
                   (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("unable to connect");
        return -1;
    }

    while(1)
    {
        fgets(buf, 100, stdin);
        send(socketfd, buf, strlen(buf) + 1, 0);
    }

    

    // receive data from server
    recv_len = recv(socketfd, buf, strlen(buf) + 1, 0);
    if (recv_len == 0) {
        printf("server disconnected!\n");
        close(socketfd);
        return 0;
    }
    if (recv_len < 0) {
        perror("error receiving data from server");
        return -1;
    }

    printf("received from server %d bytes:%s\n", recv_len, buf);

    close(socketfd);
    return 0;
}
