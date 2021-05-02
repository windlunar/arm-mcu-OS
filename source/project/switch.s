
; CONTROL[1] Stack status: 
; 1 = Alternate stack is used
; 0 = Default stack (MSP) is used
;
; If it is in the thread or base level, the alternate stack is the PSP. There is no 
; alternate stack for handler mode, so this bit must be 0 when the processor is in 
; handler mode.
;
;
; CONTROL[0] 
; 0 = Privileged in thread mode 
; 1 = User state in thread mode 
;
; If in handler mode (not thread mode), the processor operates in privileged mode.


msp_privileged	 	equ 0
msp_user 			equ 1
psp_privileged	 	equ 2
psp_user 			equ 3

	AREA SWITCH_FUNCS, CODE, READONLY
	EXPORT 	run_thread
	IMPORT	systick_enable
	IMPORT	systick_int_enable

; arg1(r0) : Stack pointer of thread (thread_context struture pointer)
run_thread PROC	
	; Switch to Process Stack
	; r0 is the input arg
	msr 	psp, r0
	mov		r0 ,#psp_user
	msr		control	,r0
	
	; pop context back from stack
	ldmfd 	sp!, {r4-r11}

	; After pop r4-r11
	; r0  <---- sp
	; r1
	; r2
	; r3
	; r12
	; lr
	; pc  <---- sp + 24   ,Here stores the entry of thread
	ldr 	lr, [sp ,#24]	; load thread_context->pc to lr
	bx		lr				; Branch to the thread

	endp



	EXPORT 	save_user_context
save_user_context PROC	
	; Save the context ,push core register to user stack
	mrs 	r0 ,psp
	stmfd	r0! ,{r4-r11}

	; r0 as the return value ,the context struct pointer should point to here.

	bx 		lr ; Back to caller
	endp


; arg1 : New thread_context pointer ,and should be the psp
	EXPORT 	switch_user_context
switch_user_context PROC	
	; pop r4-r11 back from stack(memory)
	ldmfd 	r0!, {r4-r11}

	; Update psp to another thread
	msr 	psp, r0

	bx 		lr
	endp

	END
		