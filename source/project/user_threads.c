/**
 * Implement by Allen.YY.LIN
 * 
 */

#include "../driver/usart.h"
#include "../driver/gpio.h"
#include "user_threads.h"


void (*user_threads[4])(void) = {
	thread_test1
	,thread_test2
	,thread_test3
	,thread_test4
} ;


void thread_test1(void)
{
	int count = 0 ;

	while (1) {
		printf("thread1 ,count : %d\n" ,count) ;
		count++ ;
	}
	
}


void thread_test2(void)
{
	int count = 0 ;

	while (1) {
		printf("thread2 ,count : %d\n" ,count) ;
		count++ ;
	}
}


void thread_test3(void)
{
	int count = 0 ;

	while (1) {
		printf("thread3 ,count : %d\n" ,count) ;
		count++ ;
	}
}


void thread_test4(void)
{
	int count = 0 ;

	while (1) {
		printf("thread4 ,count : %d\n" ,count) ;
		count++ ;
	}
}
