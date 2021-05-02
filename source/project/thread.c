/**
 * Implement by Allen.YY.LIN
 * 
 */

#include "../lib/common.h"
#include "systick_int.h"
#include "../driver/usart.h"
#include "../driver/gpio.h"
#include "thread.h"

uint32_t thread_id = 0 ;

/**
 * Thread's stack and these structures should at specific memory space called page
 * Remove these lines after implement page_alloc()
 * 
 */
uint8_t thread_stack[4][STACK_SIZE] ;
struct thread_info thread[4] ; 


/**
 *	Implement Thread List by Linked list
 **/

struct thread_info *thread_ready_list_head = NULL ;
struct thread_info *curr_thread ;	// Current Running Thread


void ready_list_add_tail(struct thread_info *new_node)
{
	if (thread_ready_list_head == NULL) {
		thread_ready_list_head = new_node ;
		return ;
	
	} else {	// new_node is not the first node ,find the end node
		struct thread_info *end = ready_list_find_end(thread_ready_list_head) ;

		end->next = new_node ;
		new_node->prev = end ;

		// update the head node
		end = new_node ;
	}
}


struct thread_info *ready_list_remove_head(void)
{
	struct thread_info *node = thread_ready_list_head ;
	if (node->next == NULL)	
		usart_send_str(CONSOLE_PTR,"Ready List will be empty!\n\0") ;

	thread_ready_list_head = node->next ;
	thread_ready_list_head->prev = NULL ;

	node->prev = NULL ;
	node->next = NULL ;

	return node ;
}


struct thread_info *ready_list_find_end(struct thread_info *head)
{
	while (head->next != NULL) {
		head = head->next ;
	}
	struct thread_info *end = head ;

	return end ;
}


void debug_print_ready_list(void)
{
	struct thread_info *head = thread_ready_list_head ;
	while (head != NULL) {
		printf("tid : %d " ,head->tid) ;
		head = head->next ;
	}
	printf("\n") ;
}

/**
 * Create Thread 
 */ 
void thread_create(struct thread_info *thread ,void (*thread_entry)(void) ,uint8_t *stk_bottom)
{
	// Assign thread id
	thread->tid = (uint16_t)thread_id ;
	thread_id++ ;

	// Setup stack
	uint32_t *stktop = (uint32_t *)(stk_bottom + (STACK_SIZE)) ;
	thread->stack_top = stktop ;
	thread->stack_bottom = (uint32_t *)stk_bottom ;

	// thread->context is the SP too.
	thread->context = (struct thread_context *)(thread->stack_top - 16) ;
	printf("\n1.thread->context address : %p--", thread->context) ;
	printf("thread->context point to : %p\n", &thread->context) ;
	// Setup Entry
	thread->entry = thread_entry ;
	thread->context->r11 = (uint32_t)thread_entry ;
	thread->context->pc = (thread->context->r11) ;
	thread->context->xpsr = THUMB_BIT << XPSR_T_BIT_SHIFT ;

	// Setup the state as READY
	thread->state = THREAD_READY ;

	//Add the thread to ready list
	thread->prev = NULL ;
	thread->next = NULL ;
	ready_list_add_tail(thread) ;
}



// You can implement your scheduler here
void scheduler(void)
{
	struct thread_info *de_q_thread = ready_list_remove_head() ;

	ready_list_add_tail(de_q_thread) ;

	curr_thread = thread_ready_list_head ;
	curr_thread->state = THREAD_RUNNING ;
}


void thread1_init(void)
{
	curr_thread = thread_ready_list_head ;
	curr_thread->state = THREAD_RUNNING ;

}
