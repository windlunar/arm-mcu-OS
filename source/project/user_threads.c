
#include "../driver/usart.h"
#include "../driver/gpio.h"
#include "user_threads.h"


void first_user_thread(void)
{
	while (1) {
		printf("In first_") ;
		usart_send_str(CONSOLE_PTR,"thread!\n\0");
	}
	
}

void second_user_thread(void)
{
	while (1) {
		usart_send_str(CONSOLE_PTR,"In second_user_thread!\n\0");
	}
}
