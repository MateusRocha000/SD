/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _ECHO_H_RPCGEN
#define _ECHO_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


#define ECHOPROG 0x20000001
#define ECHOVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define ECHO 1
extern  char ** echo_1(char **, CLIENT *);
extern  char ** echo_1_svc(char **, struct svc_req *);
extern int echoprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define ECHO 1
extern  char ** echo_1();
extern  char ** echo_1_svc();
extern int echoprog_1_freeresult ();
#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_ECHO_H_RPCGEN */
