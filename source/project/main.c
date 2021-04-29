
#include <stm32f10x.h>
#include "../driver/gpio.h"
#include "../driver/usart.h"
#include "../lib/common.h"
#include "../driver/systick.h"




int main(void)
{
	gpio_clk_enable() ;
	gpio_pin_mode(GPIOC ,13 ,OUTPUT) ;
	
  	usart_init(CONSOLE_PTR) ;
	
	systick_int_init(1000) ;	//10ms

	while (1) ;
	
	return 0 ;
}

