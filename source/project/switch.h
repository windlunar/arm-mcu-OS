/**
 * Implement by Allen.YY.LIN
 * 
 */

#ifndef _SWITCH_H_
#define _SWITCH_H_

#include "../core/stm32f10x.h"
#include "thread.h"

void context_switch(struct thread_context *old_context) ;

extern void run_thread(uint32_t *thread_sp) ;
extern void switch_user_context(struct thread_context *) ;




#endif
