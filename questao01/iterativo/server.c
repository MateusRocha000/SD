#include <stdio.h>
#include<stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERV_TCP_PORT 6000
#define MAX_LINE 1000
#define erro(str) {printf(str);exit(1);}

int main(int argc, char *argv[])

{  
  int  sockfd, newsockfd, clilen, n;
  struct sockaddr_in  cli_addr, serv_addr;

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)   /* abre um socket TCP */
  erro("abrindo socket\n")

  /* Liga o processo servidor ao seu endereço local */

  bzero((char *)&serv_addr, sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(SERV_TCP_PORT);

  if  (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)       erro("binding\n");

  listen(sockfd, 5);
  
  while(1){
    clilen = sizeof(cli_addr);
    printf("I'm %i Listening %i\n", getpid(), sockfd); 
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
      erro("server: accept error")
    char buf[MAX_LINE];
    
    while(1){
      n = recv(newsockfd, buf, MAX_LINE, 0);
      if (n == 0) {
        close(newsockfd);       
        break;
      }
      printf("%s\n", buf);
      sleep(5);       
      send(newsockfd, buf, strlen(buf) + 1, 0); /* process the request */
    }
  }

  return 0;
}
