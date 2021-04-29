
#include <stm32f10x.h>
#include "../driver/gpio.h"
#include "../driver/usart.h"
#include "../lib/common.h"
#include "../driver/systick.h"




int main(void)
{
   usart_init(CONSOLE_PTR) ;

	while (1) {
		delay(1000) ;
		usart_send_str("Hello World!\n\0");
	}
	
	return 0 ;
}



