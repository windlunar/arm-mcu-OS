
#include <stm32f10x.h>
#include "../driver/gpio.h"
#include "../driver/usart.h"
#include "../lib/common.h"



int main(void)
{
  usart_init(CONSOLE_PTR) ;

	usart_send_str("Hello World!\n\0");

	return 0 ;
}
