
#include "../lib/common.h"
#include "systick_int.h"
#include "../driver/usart.h"
#include "../driver/gpio.h"



void SysTick_Handler(void)
{
	gpio_pin_toggle(GPIOC ,13) ; // toggle PC13 
	printf("In SysTick_") ;
	usart_send_str(CONSOLE_PTR,"Handler!\n\0");
}
