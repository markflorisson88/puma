#ifndef _LOG_H

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

int log_fd; /* File descriptor for log file */

static char*
getTimeStamp(char *time_stamp)
{
	time_t current_time;

	current_time = time(0);
	strftime(time_stamp,9,"%H:%M:%S",localtime(&current_time));

	return(time_stamp);
}



static void
debug_msg(const char* msg, ...)
{
	va_list list;
	char time_stamp[16] = {'\0'};
	char line[4096] = {'\0'};
	
	getTimeStamp(time_stamp);

	va_start(list,msg);
#ifdef DEBUG
	sprintf(line,"%s:%s",time_stamp,msg);	
	vfprintf(stdout,line,list);
#endif
	va_end(list);
}

static void
error_msg(const char* msg, ...)
{
	va_list list;
	char time_stamp[16] = {'\0'};
	char line[4096] = {'\0'};
	
	getTimeStamp(time_stamp);

	va_start(list,msg);

	sprintf(line,"%s:%s",time_stamp,msg);	
	vfprintf(stderr,line,list);

	va_end(list);
}

#endif
