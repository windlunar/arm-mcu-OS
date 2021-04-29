
#include "../lib/common.h"
#include "systick_int.h"
#include "../driver/usart.h"



void SysTick_Handler(void)
{
	GPIOC->ODR ^= (1 << 13)	; /* toggle PC13 */
	usart_send_str("Hello World!\n\0");
}
