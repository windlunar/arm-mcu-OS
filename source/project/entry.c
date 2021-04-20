
#include "../core/stm32f10x.h"

/***************************************************************************************
void delay_ms(uint16_t t);

int main()
{
	RCC->APB2ENR |= 0xFC; //Enable the clocks for GPIO ports 
	
	GPIOC->CRH = 0x33333333; //PC8 to PC15 as outputs

	while (1) {		
		GPIOC->ODR &= (unsigned int)(~(1 << 13)); //make usr led low
		delay_ms(1000);	//wait 1000ms
		GPIOC->ODR |= (unsigned int)(1 << 13); //make usr led high
		delay_ms(1000);	//wait 1000ms
	}
}



//The following delay is tested with Keil and 72MHz
void delay_ms(uint16_t t)
{
	volatile unsigned long l = 0;
	
	for(uint16_t i = 0; i < t; i++)
		for(l = 0; l < 6000; l++) ;
}
***************************************************************************************/
/***************************************************************************************/
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
/***************************************************************************************/
