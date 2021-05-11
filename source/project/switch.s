.thumb
.syntax unified

// CONTROL[1] Stack status: 
// 1 = Alternate stack is used
// 0 = Default stack (MSP) is used
//
// If it is in the thread or base level, the alternate stack is the PSP. There is no 
// alternate stack for handler mode, so this bit must be 0 when the processor is in 
// handler mode.
//
//
// CONTROL[0] 
// 0 = Privileged in thread mode 
// 1 = User state in thread mode 
//
// If in handler mode (not thread mode), the processor operates in privileged mode.


.equ	msp_privileged,	 0
.equ	msp_user, 		 1
.equ	psp_privileged,	 2
.equ	psp_user, 		 3

	//AREA SWITCH_FUNCS, CODE, READONLY
	//EXPORT 	run_thread
	//IMPORT	systick_enable
	//IMPORT	systick_int_enable

// arg1(r0) : Stack pointer of thread (thread_context struture pointer)
.global run_thread
.align	2
run_thread:	
	// Switch to Process Stack
	// r0 is the input arg
	msr psp, r0
	mov		r0 ,#psp_user
	msr		control	,r0
	
	// pop context back from stack
	ldmfd 	sp!, {r4-r11}

	// After pop r4-r11
	// r0  <---- sp
	// r1
	// r2
	// r3
	// r12
	// lr
	// pc  <---- sp + 24   ,Here stores the entry of thread
	ldr 	lr, [sp ,#24]	// load thread_context->pc to lr
	bx		lr				// Branch to the thread








// arg1 : New thread_context pointer ,and should be the psp
.global switch_user_context
.align	2
switch_user_context:	
	// pop r4-r11 back from stack(memory)
	ldmfd 	r0!, {r4-r11}

	// Update psp to another thread
	msr 	psp, r0

	// Directly return to user state
	ldr		lr ,=0xfffffffd

	bx 		lr





.type SysTick_Handler, %function
.global SysTick_Handler
.align	2
SysTick_Handler :
	b 	save_user_context


.align	2
save_user_context:	
	// Save the context ,push core register to user stack
	mrs 	r0 ,psp
	stmfd	r0! ,{r4-r11}

	bl 		context_switch