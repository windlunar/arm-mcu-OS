
#include "../lib/common.h"
#include "systick_int.h"
#include "../driver/usart.h"
#include "../driver/gpio.h"
#include "thread.h"

uint32_t thread_id = 0 ;
struct thread_context first_thread_context ;
struct thread_info first_thread ;
uint8_t first_thread_stack[STACK_SIZE] ;


void thread_create(struct thread_info *thread ,void (*thread_entry)(void) ,uint8_t *stk_bottom)
{
	// Assign thread id
	thread->tid = (uint16_t)thread_id ;
	thread_id++ ;

	// Setup stack
	uint32_t *stktop = (uint32_t *)(stk_bottom + (STACK_SIZE)) ;
	
	thread->stack_top = stktop ;
	thread->stack_bottom = (uint32_t *)stk_bottom ;

	// This should be the SP
	thread->context = (struct thread_context *)(thread->stack_top - 10) ;

	// Setup Entry
	thread->entry = thread_entry ;
	thread->context->lr = (uint32_t)thread_entry ;

	thread->state = THREAD_READY ;
}
