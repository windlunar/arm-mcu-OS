
#ifndef _USER_THREADS_H_
#define _USER_THREADS_H_

#include <stm32f10x.h>
#include "../lib/common.h"

extern void (*user_threads[4])(void) ;

void thread_test1(void) ;
void thread_test2(void) ;
void thread_test3(void) ;
void thread_test4(void) ;

#endif
