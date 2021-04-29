
#include <stm32f10x.h>
#include "../driver/gpio.h"
#include "../driver/usart.h"
#include "../lib/common.h"
#include "../driver/systick.h"




int main(void)
{
	gpio_clk_enable() ;
	
	config_gpio_mode_bits(GPIOC ,13 ,MODE_OUTPUT_50M) ;
	config_gpio_cnf_bits(GPIOC ,13 ,ALT_OUT_PUSHPULL) ;
	
  usart_init(CONSOLE_PTR) ;
	
	systick_int_init(1000) ;	//10ms

	while (1) ;
	
	return 0 ;
}

