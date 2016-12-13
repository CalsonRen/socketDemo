#include "unp.h"
#include <syslog.h>
#include <stdarg.h>

int daemon_proc; /* set nozero by daemon_init(); */


static void err_doit(int, int, const char*, va_list);


/* Unfatal error related to system call */

void err_quit(const char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	err_doit(0, LOG_INFO, fmt, ap);
	va_end(ap);
}


/* Fatal error related to system call */

void err_sys(const char*fmt, ...)
{
	va_list ap;	
	va_start(ap, fmt);
	err_doit(1, LOG_ERR, fmt, ap);
	va_end(ap);
	return;
}


/* Nofatal error unrelated to system call*/

void err_msg(const char*fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	err_doit(0, LOG_INFO, fmt, ap);
	va_end(ap);
	return;
}


/* print msg and return to the caller
 * caller specifies "errorflag" and "level" */

static void err_doit(int errnoflag, int level, const char* fmt, va_list ap)
{
	int errno_save, n;
	char buf[MAXLINE + 1];
	errno_save = errno;
#ifdef HAVE_VSNPRINTF
	vsnprintf(buf, MAXLINE, fmt, ap); /*safe print */
#else
	vsprintf(buf, fmt, ap);
#endif
	n = strlen(buf);
	if(errorflag)
		snprintf(buf + n, MAXLINE - n, ": %s", strerror(errno_save));
	strcat(buf, "\n");
	
	if(daemon_proc)
	{
		syslog(level, buf);
	}
	else
	{
		fflush(stdout);
		fputs(buf, steerr);
		fflush(stderr);
	}
}
