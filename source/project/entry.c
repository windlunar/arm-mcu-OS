
#include "../core/stm32f10x.h"
#include "../lib/common.h"
#include "../driver/gpio.h"
#include "../driver/usart.h"
#include "../driver/systick.h"



void main(void)
{
    usart_init(CONSOLE_PTR) ;
	systick_int_init(1000) ; //10ms

	while (1) ;
}

