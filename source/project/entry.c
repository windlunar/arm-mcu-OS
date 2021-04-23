
#include "../core/stm32f10x.h"
#include "../driver/gpio.h"
#include "../driver/usart.h"
#include "../lib/common.h"


void main(void)
{
    usart_init(CONSOLE_PTR) ;
    
	SET_SINGLE_BIT(USART2->CR1 ,2) ;
	SET_SINGLE_BIT(USART2->CR1 ,3) ;
	SET_SINGLE_BIT(USART2->CR1 ,13) ;

	usart_send_str("Hello World!\n\0");

	while (1);
}

