
#include "usart.h"
#include "gpio.h"
#include "../lib/common.h"

void usart_send_char(USART_TypeDef * usartx ,char ch)
{
	while (!((usartx->SR) & USART_SR_TXE));

	USART2->DR = ch;
}



void usart_send_str(USART_TypeDef * usartx ,const char *s)
{
	while (*s) {
		while (!((usartx->SR) & USART_SR_TXE));

		USART2->DR = *s;

		s++ ;
	}
}


void usart_clk_enable(void)
{
	SET_BIT(RCC->APB2ENR ,RCC_APB2ENR_USART1EN) ;
	SET_BIT(RCC->APB1ENR ,RCC_APB1ENR_USART2EN) ;
	//SET_BIT(RCC->APB1ENR ,RCC_APB1ENR_USART3EN) ; // Enable USART3 ,qemu failed but success at keil
}


/**
 * USART1 	TX----PA9
 * 			RX----PA10
 * 
 * USART2	TX----PA2
 * 			RX----PA3
 * 
 * USART3	TX----PB10
 * 			RX----PB11
 * 
 */ 
int config_gpio_for_usart(USART_TypeDef * usartx)
{
	if (usartx == USART1) {
		//Pull-up PA10 for USART1 ,GPIOA->ODR |= (1 << 10) ;	
		SET_SINGLE_BIT(GPIOA->ODR ,10) ;

		// Config GPIO for USART1
		config_gpio_mode_bits(GPIOA ,9 ,MODE_OUTPUT_50M) ;
		config_gpio_cnf_bits(GPIOA ,9 ,ALT_OUT_PUSHPULL) ;
		config_gpio_mode_bits(GPIOA ,10 ,MODE_INPUT) ;

	} else if (usartx == USART2) {
		//Pull-up PA3 for USART2 ,GPIOA->ODR |= (1 << 3) ;	
		SET_SINGLE_BIT(GPIOA->ODR ,3) ;

		//Config GPIO for USART2
		config_gpio_mode_bits(GPIOA ,2 ,MODE_OUTPUT_50M) ;
		config_gpio_cnf_bits(GPIOA ,2 ,ALT_OUT_PUSHPULL) ;
		config_gpio_mode_bits(GPIOA ,3 ,MODE_INPUT) ;

	} else if (usartx == USART3) {
		//Pull-up PB11 for USART3 ,GPIOB->ODR |= (1 << 11) ;	
		SET_SINGLE_BIT(GPIOB->ODR ,11) ;

		//Config GPIO for USART3
		config_gpio_mode_bits(GPIOB ,10 ,MODE_OUTPUT_50M) ;
		config_gpio_cnf_bits(GPIOB ,10 ,ALT_OUT_PUSHPULL) ;
		config_gpio_mode_bits(GPIOB ,11 ,MODE_INPUT) ;

	} else {
		return -1 ;
	}

	return 0 ;

}


void usart_init(USART_TypeDef * usartx)
{
	gpio_clk_enable() ;	// Enable clks for GPIOA and GPIOB
	config_gpio_for_usart(usartx) ;	//Config GPIO for USARTx
	
	usart_clk_enable() ;

	// Enable USART
	usart_enable(usartx) ;
}


void usart_enable(USART_TypeDef * usartx)
{
	// Enable Receiver
	SET_SINGLE_BIT(usartx->CR1 ,2) ;

	// Enable Transmitter
	SET_SINGLE_BIT(usartx->CR1 ,3) ;

	//Enable USART
	SET_SINGLE_BIT(usartx->CR1 ,13) ;
}
