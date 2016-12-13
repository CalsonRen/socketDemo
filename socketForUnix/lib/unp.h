#ifndef _unp_h
#define _unp_h

#include "unp.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> /* inet  */
#include <errno.h>
#include <stdlib.h>
#include <string.h>


/* Miscellaneous constant */
#define MAXLINE 4096 /*max text line length*/
#define BUFFSIZE 8192

/* prototype for socket wrapper function */
int Accept(int, struct sockaddr*, socklen_t*);
void Bind(int, const struct sockaddr*, socklen_t);
void Connect(int, const struct sockaddr*, socklen_t);
void Listen(int, int);
int Socket(int, int, int);


/* prototype for error handler functiohn */
void err_quit(const char*);
void err_msg(const char*);
void err_sys(const char*);

/* prototype for our own lib functions */
int daemon_init(const char*, int);
