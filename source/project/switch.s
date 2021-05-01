
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

	AREA RUN_FIRST_THREAD, CODE, READONLY
	EXPORT run_first_thread

; arg1 : Stack pointer of thread
run_first_thread PROC	
	; Switch to Process Stack
	; r0 is the input arg
	msr 	psp, r0
	mov		r0 ,#psp_user
	msr		control	,r0

	; pop registers back from stack
	ldmfd 	sp!, {r4-r12 ,lr}	

	bx lr ; Branch to the thread
	endp



	END
		