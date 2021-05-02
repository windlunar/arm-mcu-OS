
#ifndef _SWITCH_H_
#define _SWITCH_H_

#include <stm32f10x.h>
#include "thread.h"


extern void run_thread(uint32_t *thread_sp) ;
extern struct thread_context *save_user_context(void) ;
extern void switch_user_context(struct thread_context *) ;

#endif
