/**
 * Implement by Allen.YY.LIN
 * 
 */

#include "../lib/common.h"
#include "../driver/usart.h"
#include "../driver/gpio.h"
#include "../driver/systick.h"
#include "switch.h"



void context_switch(struct thread_context *old_context)
{
	curr_thread->context = old_context ;

	systick_disable() ;

	scheduler() ;
	
	systick_enable() ;

	switch_user_context(curr_thread->context) ;

}
