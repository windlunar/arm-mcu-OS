
#include "../lib/common.h"
#include "systick_int.h"
#include "../driver/usart.h"
#include "../driver/gpio.h"



void SysTick_Handler(void)
{
	gpio_pin_toggle(GPIOC ,13) ; // toggle PC13 
	usart_send_str("In SysTick_Handler!\n\0");
}
