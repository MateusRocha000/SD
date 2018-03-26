#include <stdio.h>
#include <string.h>
#include "echo.h"
int main(int argc, char **argv)
{
  CLIENT *clnt;
//  char **result;
  char ** result;
  char *server;
  // try to get the server address from command line
  if (argc != 3) {
    fprintf(stderr, "Usage is the following: %s server\n", argv[0]);
    return -1;
  }
  server = argv[1];
  // create the client
  clnt = clnt_create(server, ECHOPROG, ECHOVERS, "udp"); //udp may be set to tcp
  if (clnt == NULL) {
    clnt_pcreateerror(server);
    return -1;
  }
  // call the function
  result = echo_1(&argv[2] , clnt);
  if (result == NULL) {
    clnt_perror(clnt, server);
  printf("duhh\n");
    return -1;
  }
  // print the value obtained from the call
  printf("The str received is %s\n", *result);
  // destroy the client
  clnt_destroy(clnt);
  return 0;
}