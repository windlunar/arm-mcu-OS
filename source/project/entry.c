
#include "../core/stm32f10x.h"
#include "../driver/gpio.h"
#include "../driver/usart.h"


void main(void)
{
    usart_init(CONSOLE_PTR) ;

    USART2->CR1 = 0x0000000C;
    USART2->CR1 |= 0x2000;

	usart_send_str("Hello World!\n\0");

	while (1);
}

