#include <stdio.h>
#include "echo.h"
#define STR_SIZE 100

char ** echo_1_svc(char **msg, struct svc_req *req)
{
  static int result = 0;
  result++;
  char **buf = (char**) malloc(sizeof(char*));
  *buf = (char*) malloc(sizeof(char) * STR_SIZE);
  int size = snprintf(NULL, 0, " %s %d\n", *msg, result);
  snprintf(*buf, size + 1, " %s %d\n", *msg, result);
  return((char**)buf);
}