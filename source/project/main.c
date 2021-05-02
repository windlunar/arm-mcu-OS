// "C:\\Users\\user\\AppData\\Local\\Arm\\Packs\\Keil\\STM32F1xx_DFP\\2.3.0\\Device\\Include"

/**
 * Implement by Allen.YY.LIN
 * 
 */

#include <stm32f10x.h>
#include "../driver/gpio.h"
#include "../driver/usart.h"
#include "../lib/common.h"
#include "../driver/systick.h"
#include "thread.h"
#include "user_threads.h"
#include "switch.h"


int main(void)
{
	gpio_clk_enable() ;
	gpio_pin_mode(GPIOC ,13 ,OUTPUT) ;
	
  	usart_init(CONSOLE_PTR) ;
	
	systick_int_init(1000) ;	//10ms

	for (int i = 0 ; i < 4; i++)
		thread_create(&thread[i] ,user_threads[i] ,thread_stack[i]) ;


	thread1_init() ;	
	systick_enable() ;

	run_thread((uint32_t *)curr_thread->context) ;

	// Never reach Here
	printf("Never Print This Line.\n") ;

	return 0 ;
}

