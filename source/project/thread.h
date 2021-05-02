/**
 * Implement by Allen.YY.LIN
 * 
 */

#ifndef _THREAD_H_
#define _THREAD_H_

#include <stm32f10x.h>

/**
 * Thread's stack and these structures should at specific memory space called page
 * Remove these lines after implement page_alloc()
 * 
 */ 
#define STACK_SIZE  (512)

/**
 * 
 */

#define THREAD_READY            (0)
#define THREAD_RUNNING          (1)
#define THREAD_TERMINATE        (2)

#define THUMB_BIT               (0x00000001)
#define XPSR_T_BIT_SHIFT       (24)

//extern struct thread_info *thread_ready_list_head ;
extern struct thread_info *curr_thread ;

/**
 * stmfd sp! ,{r0-r3}
 * r3
 * r2
 * r1
 * r0
 * Higher reg num push to stack first
 * 
 * When an exception take place, the registers r0-r3 ,lr ,pc, and psr are pushed
 * to the stack automatically.
 * 
 * --------   <---original sp
 * xPSR
 * pc
 * lr
 * r12
 * r3
 * r2
 * r1
 * r0
 * 
 * r11
 * r10
 * r9
 * r8
 * r7
 * r6
 * r5
 * r4 <----- After storing the context ,sp should point to here
 */ 
struct thread_context{
    uint32_t r4 ;   // <------- sp
    uint32_t r5 ;
    uint32_t r6 ;
    uint32_t r7 ;
    uint32_t r8 ;
    uint32_t r9 ;
    uint32_t r10 ;
    uint32_t r11 ;
    //
    uint32_t r0 ;
    uint32_t r1 ;
    uint32_t r2 ;
    uint32_t r3 ;
    uint32_t r12 ;
    uint32_t lr ;
    uint32_t pc ;
    uint32_t xpsr ;
};

struct thread_info{
    uint32_t tid ;
    uint32_t state ;
    void (*entry)(void) ;
    uint32_t *stack_top ;
    uint32_t *stack_bottom ;
    struct thread_context *context ;

    struct thread_info *prev ;
    struct thread_info *next ;
};


void thread_create(struct thread_info *thread ,void (*thread_entry)(void) ,uint8_t *stack_bottom) ;
void ready_list_add_tail(struct thread_info *new_node) ;
struct thread_info *ready_list_remove_head(void) ;
struct thread_info *ready_list_find_end(struct thread_info *head) ;
void debug_print_ready_list(void) ;
void scheduler(void) ;
void thread1_init(void) ;

/**
 * Thread's stack and these structures should at specific memory space called page
 * Remove these lines after implement page_alloc()
 * 
 */
extern uint8_t thread_stack[4][STACK_SIZE] ;
extern struct thread_info thread[4] ;

#endif
