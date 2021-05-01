// "C:\\Users\\user\\AppData\\Local\\Arm\\Packs\\Keil\\STM32F1xx_DFP\\2.3.0\\Device\\Include"
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

	thread_create(&first_thread ,first_user_thread ,first_thread_stack) ;
	run_first_thread((uint32_t *)first_thread.context) ;

	//
	printf("Never Print This.\n") ;
	
	return 0 ;
}

