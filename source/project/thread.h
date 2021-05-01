
#ifndef _THREAD_H_
#define _THREAD_H_

#include <stm32f10x.h>

extern struct thread_context first_thread_context ;
extern uint8_t first_thread_stack[256] ;
extern struct thread_info first_thread ;

#define STACK_SIZE  (256)
#define THREAD_READY        (0)
#define TRHRAD_RUNNING      (1)
#define THREAD_TERMINATE    (2)

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
 * lr
 * sp
 * r12
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
    uint32_t r4 ;
    uint32_t r5 ;
    uint32_t r6 ;
    uint32_t r7 ;
    uint32_t r8 ;
    uint32_t r9 ;
    uint32_t r10 ;
    uint32_t r11 ;
    uint32_t r12 ;
    uint32_t lr ;
};

struct thread_info{
    uint16_t tid ;
    uint16_t state ;
    void (*entry)(void) ;
    uint32_t *stack_top ;
    uint32_t *stack_bottom ;
    struct thread_context *context ;
};

void thread_create(struct thread_info *thread ,void (*thread_entry)(void) ,uint8_t *stack_bottom) ;

#endif
