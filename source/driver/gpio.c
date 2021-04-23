
#include "gpio.h"
#include "../lib/common.h"


void gpio_clk_enable(void)
{
	// Enable the clocks for GPIOA ports  ,RCC->APB2ENR |= RCC_APB2ENR_IOPAEN ;	
	// Enable the clks for GPIOB ,RCC->APB2ENR |= RCC_APB2ENR_IOPBEN ;	
	SET_BIT(RCC->APB2ENR ,RCC_APB2ENR_IOPAEN) ;
	SET_BIT(RCC->APB2ENR ,RCC_APB2ENR_IOPBEN) ;
}


int config_gpio_mode(GPIO_TypeDef * GPIOx ,uint8_t pin ,uint8_t mode_bits)
{
	if (pin <= 7) {
		GPIOx->CRL |= (mode_bits << (4 * pin)) ;

	} else if (pin <= 15) {
		GPIOx->CRH |= (mode_bits << (4 * (pin - 7))) ;

	} else {
		return -1 ;
	}

	return 0 ;
}


int config_gpio_cnf(GPIO_TypeDef * GPIOx ,uint8_t pin ,uint8_t cnf_bits)
{
	uint8_t bit_shift ;

	if (pin <= 7) {
		bit_shift = (4 * pin) + 2 ;
		GPIOx->CRL |= (cnf_bits << bit_shift) ;

	} else if (pin <= 15) {
		bit_shift = (4 * (pin - 7)) + 2 ;
		GPIOx->CRH |= (cnf_bits << bit_shift) ;

	} else {
		return -1 ;
	}

	return 0 ;
}
