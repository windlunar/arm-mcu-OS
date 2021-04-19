
#include "../core/stm32f10x.h"


void puts(char *str)
{
	while (*str) {
		while (!((USART2->SR) & USART_SR_TXE));

		USART2->DR = *str & 0xFF;

		str++ ;
	}
}


void main(void)
{
    RCC->APB2ENR |= 0xFC; //Enable the clocks for GPIO ports 
    RCC->APB1ENR |= (unsigned int)(1 << 17) ; //Enable USART2

    GPIOA->CRL = 0x00004B00; //
	GPIOA->CRH = 0x44444444; //

    USART2->CR1 = 0x0000000C;
    USART2->CR1 |= 0x2000;

	puts("Hello World !\n");

	while (1);
}
