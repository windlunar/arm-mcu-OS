/**
 * Implement by Allen.YY.LIN
 * 
 */

#include "../lib/common.h"
#include "systick_int.h"
#include "../driver/usart.h"
#include "../driver/gpio.h"


void SysTick_Handler(void)
{
	curr_thread->context = save_user_context() ;

	systick_disable() ;

	scheduler() ;
	
	systick_enable() ;

	switch_user_context(curr_thread->context) ;
	
	}
