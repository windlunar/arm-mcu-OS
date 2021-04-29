
#ifndef _SYSTICK_H_
#define _SYSTICK_H_

#include "../core/stm32f10x.h"


/**
 * SysTick sturcture is defined at core_cm3.h by ARM
 * 
 */ 


/**
 * CLK Source
 */
#define SYSTICK_AHBCLK      (1)
#define SYSTICK_AHBCLK_DIV_BY_EIGHT  (0)    //Default

#define CLK_MHZ     (72)


void systick_enable(void) ;
void systick_disable(void) ;
void systick_choose_clksrc(uint32_t clk_src) ;
int systick_count_zero(void) ;
void delay(uint32_t us) ;

void systick_int_enable(void) ;
void systick_int_disable(void) ;

void systick_int_init(uint32_t slice_us) ;


#endif
