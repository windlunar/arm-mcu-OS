
#ifndef _USART_H_
#define _USART_H_

#include "../core/stm32f10x.h"

#define CONSOLE_PTR		USART2

void usart_send_str(char *s) ;
void usart_init(USART_TypeDef * usartx) ;
void usart_clk_enable(void) ;
int config_gpio_for_usart(USART_TypeDef * usartx) ;

#endif
