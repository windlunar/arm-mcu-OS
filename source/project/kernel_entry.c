// "C:\\Users\\user\\AppData\\Local\\Arm\\Packs\\Keil\\STM32F1xx_DFP\\2.3.0\\Device\\Include"

/**
 * Implement by Allen.YY.LIN
 * 
 */

#include "../core/stm32f10x.h"
#include "../driver/gpio.h"
#include "../driver/usart.h"
#include "../lib/common.h"
#include "../driver/systick.h"
#include "thread.h"
#include "user_threads.h"
#include "switch.h"


int main(void)
{	
  	usart_init(CONSOLE_PTR) ;
	
	systick_int_init(100000) ;	//100ms


	for (int i = 0 ; i < 4; i++)
		thread_create(&thread[i] ,user_threads[i] ,thread_stack[i]) ;


	first_thread_init() ;	
	systick_enable() ;

	run_thread((uint32_t *)curr_thread->context) ;

	// Never reach Here
	usart_send_str(CONSOLE_PTR, "Never Print This Line.\n") ;

	return 0 ;
}

