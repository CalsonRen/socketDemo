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
#include <stdio.h>


/* Miscellaneous constant */
#define MAXLINE 4096 /*max text line length*/
#define BUFFSIZE 8192
#define SERV_PORT 9877
#define LISTENQ 1024

/* prototype for socket wrapper function */
int Accept(int, struct sockaddr*, socklen_t*);
void Bind(int, const struct sockaddr*, socklen_t);
void Connect(int, const struct sockaddr*, socklen_t);
void Listen(int, int);
int Socket(int, int, int);


/* prototype for unix wrapper funtion */
pid_t Fork(void);
void Close(int);
int Open(const char* , int, mode_t);



/* prototype for error handler functiohn */
void err_quit(const char*, ...);
void err_msg(const char*, ...);
void err_sys(const char*, ...);


/* prototype for stdio wrapper functions */
char* Fgets(char*, int, FILE*);
void Fputs(const char*, FILE*);
ssize_t Readline(int, void*, size_t);
void Writen(int, void*, size_t);

/* prototype for our own lib functions */
int daemon_init(const char*, int);
void Inet_pton(int ,const char*, void*);
const char* Inet_ntop(int, const void*, char*, size_t);
void str_cli(FILE*, int);
void str_echo(int);
#endif
