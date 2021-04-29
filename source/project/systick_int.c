
#include "../core/stm32f10x.h"
#include "../lib/common.h"
#include "systick_int.h"
#include "../driver/usart.h"



void SysTick_Handler(void)
{
	usart_send_str("Hello World!\n\0");
}
