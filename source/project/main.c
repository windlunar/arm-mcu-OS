
#include "../core/stm32f10x.h"



void usart2_putc(unsigned char c);
void usart2_send_str(char *s) ;


int main()
{
	// Enable USART2 clock
	SET_BIT(RCC->APB1ENR ,RCC_APB1ENR_USART2EN) ;

	// Enable GPIOA clock
	SET_BIT(RCC->APB2ENR ,RCC_APB2ENR_IOPAEN) ;

	// Config PA2 as Tx(alt output) ,PA3 as Rx (input)
	GPIOA->CRL = 0x44448B44 ; 

	// Pull-up rx
	SET_BIT(GPIOA->ODR ,GPIO_ODR_ODR3) ;

	// Enable USART2 ,RX ,TX
	SET_BIT(USART2->CR1 ,USART_CR1_UE | USART_CR1_RE | USART_CR1_TE) ;

	// Setting Baud Rate
	USART2->BRR = 3750; 

	usart2_send_str("Hello World !\r\n") ;

	for(;;) ;

	return 0 ;
}


void usart2_putc(unsigned char c)
{
	while (((USART2->SR) & USART_SR_TXE) == 0) ;

	USART2->DR = c;
}


void usart2_send_str(char *s)
{
	while (*s) {
		usart2_putc(*s) ;

		s++ ;
	}
}

