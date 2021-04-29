
#include "systick.h"
#include "../lib/common.h"

void systick_enable(void)
{
	SET_SINGLE_BIT(SysTick->CTRL ,0) ;
}



void systick_disable(void)
{
	CLEAR_SINGLE_BIT(SysTick->CTRL ,0) ;
}


void systick_choose_clksrc(uint32_t clk_src)
{
	if (clk_src == SYSTICK_AHBCLK)
		SET_SINGLE_BIT(SysTick->CTRL ,2) ;
	
	else 
		CLEAR_SINGLE_BIT(SysTick->CTRL ,2) ;
}


/**
 * True : Has counted to zero
 * False :Not yet
 */ 
int systick_count_zero(void)
{
	return SysTick->CTRL & SysTick_CTRL_COUNTFLAG ;
}


/**
 * Non Interrupt Methods
 * 
 * delay = (N + 1) / clk
 * (N + 1) = delay × clk = 0.001 sec × 72 MHz = 72,000
 * ==> N = 72,000 – 1 = 71999
 * 
 */ 
void delay(uint32_t us) 
{
	uint32_t load_val = (us * CLK_MHZ) - 1 ;

	SysTick->LOAD = load_val ;
	systick_choose_clksrc(SYSTICK_AHBCLK) ;
	systick_enable() ;

	while(systick_count_zero() == FALSE) ;

	systick_disable() ;
}




void systick_int_enable(void)
{
	SET_SINGLE_BIT(SysTick->CTRL ,1) ;
}


void systick_int_disable(void)
{
	CLEAR_SINGLE_BIT(SysTick->CTRL ,1) ;
}


void systick_int_init(uint32_t slice_us)
{
	uint32_t load_val = (slice_us * CLK_MHZ) - 1 ;

	SysTick->LOAD = load_val ;

	systick_choose_clksrc(SYSTICK_AHBCLK) ;
	systick_enable() ;
	systick_int_enable() ;
}

