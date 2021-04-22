
#include "usart.h"
#include "gpio.h"

void usart_send_str(char *s)
{
	while (*s) {
		while (!((USART2->SR) & USART_SR_TXE));

		USART2->DR = *s;

		s++ ;
	}
}


void usart_clk_enable(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN ;	// Enable USART1
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN ;	// Enable USART2
	//RCC->APB1ENR |= RCC_APB1ENR_USART3EN ;	// Enable USART3 ,qemu failed
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
		GPIOA->ODR |= (1 << 10) ;	//Pull-up PA10 for USART1

		// Config GPIO for USART1
		config_gpio_mode(GPIOA ,9 ,MODE_OUTPUT_50M) ;
		config_gpio_cnf(GPIOA ,9 ,ALT_OUT_PUSHPULL) ;
		config_gpio_mode(GPIOA ,10 ,MODE_INPUT) ;

	} else if (usartx == USART2) {
		GPIOA->ODR |= (1 << 3) ;	//Pull-up PA3 for USART2

		//Config GPIO for USART2
		config_gpio_mode(GPIOA ,2 ,MODE_OUTPUT_50M) ;
		config_gpio_cnf(GPIOA ,2 ,ALT_OUT_PUSHPULL) ;
		config_gpio_mode(GPIOA ,3 ,MODE_INPUT) ;

	} else if (usartx == USART3) {
		GPIOB->ODR |= (1 << 11) ;	//Pull-up PB11 for USART3

		//Config GPIO for USART3
		config_gpio_mode(GPIOB ,10 ,MODE_OUTPUT_50M) ;
		config_gpio_cnf(GPIOB ,10 ,ALT_OUT_PUSHPULL) ;
		config_gpio_mode(GPIOB ,11 ,MODE_INPUT) ;

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
}

