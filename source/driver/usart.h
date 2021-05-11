
#ifndef _USART_H_
#define _USART_H_

#include "../core/stm32f10x.h"

#define CONSOLE_PTR		USART2

/**
 * CR1 bits define
 * 
 */ 
#define TRANSMITTER_BIT_SHIFT	(3)
#define TRANSMITTER_ENABLE		(1)
#define TRANSMITTER_DISABLE		(0)

#define RECEIVER_BIT_SHIFT		(2)
#define RECEIVER_ENABLE			(1)
#define RECEIVER_DISABLE		(0)


void usart_send_char(USART_TypeDef * usartx ,char ch) ;
void usart_send_str(USART_TypeDef * usartx ,const char *s) ;
void usart_init(USART_TypeDef * usartx) ;
void usart_clk_enable(void) ;
int config_gpio_for_usart(USART_TypeDef * usartx) ;
void usart_enable(USART_TypeDef * usartx) ;

#endif
