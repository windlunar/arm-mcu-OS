/**
 * Implement by Allen.YY.LIN
 * 
 */

#include "../driver/usart.h"
#include "../driver/gpio.h"
#include "user_threads.h"


const char *s1 = "thread1\n\0" ;
const char *s2 = "thread2\n\0" ;
const char *s3 = "thread3\n\0" ;
const char *s4 = "thread4\n\0" ;


void (*user_threads[4])(void) = {
	thread_test1
	,thread_test2
	,thread_test3
	,thread_test4
} ;


void thread_test1(void)
{
	while (1) {
		usart_send_str(CONSOLE_PTR ,s1) ;
		//usart_send_char(CONSOLE_PTR ,0x31) ;
		//usart_send_char(CONSOLE_PTR ,0xa) ;
		//usart_send_char(CONSOLE_PTR ,0xd) ;
	}
	
}


void thread_test2(void)
{
	while (1) {
		usart_send_str(CONSOLE_PTR ,s2) ;
		//usart_send_char(CONSOLE_PTR ,0x32) ;
		//usart_send_char(CONSOLE_PTR ,0xa) ;
		//usart_send_char(CONSOLE_PTR ,0xd) ;
	}
}


void thread_test3(void)
{
	while (1) {
		usart_send_str(CONSOLE_PTR ,s3) ;
		//usart_send_char(CONSOLE_PTR ,0x33) ;
		//usart_send_char(CONSOLE_PTR ,0xa) ;
		//usart_send_char(CONSOLE_PTR ,0xd) ;
	}
}


void thread_test4(void)
{
	while (1) {
		usart_send_str(CONSOLE_PTR ,s4) ;
		//usart_send_char(CONSOLE_PTR ,0x34) ;
		//usart_send_char(CONSOLE_PTR ,0xa) ;
		//usart_send_char(CONSOLE_PTR ,0xd) ;
	}
}
