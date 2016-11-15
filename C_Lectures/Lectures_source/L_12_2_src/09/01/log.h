#ifndef __LOG__H__

#define __LOG__H__


extern FILE *flog;


int log_init(const char *name);


void log_close(void);


#endif  //  __LOG__H__
