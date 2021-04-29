
#include "gpio.h"
#include "../lib/common.h"


void gpio_clk_enable(void)
{
	// Enable the clocks for GPIOA ports  ,RCC->APB2ENR |= RCC_APB2ENR_IOPAEN ;	
	// Enable the clks for GPIOB ,RCC->APB2ENR |= RCC_APB2ENR_IOPBEN ;	
	SET_BIT(RCC->APB2ENR ,RCC_APB2ENR_IOPAEN) ;
	SET_BIT(RCC->APB2ENR ,RCC_APB2ENR_IOPBEN) ;
	SET_BIT(RCC->APB2ENR ,RCC_APB2ENR_IOPCEN) ;
}


int config_gpio_mode_bits(GPIO_TypeDef * GPIOx ,uint8_t pin ,uint8_t mode_bits)
{
	if (pin <= 7) {
		GPIOx->CRL |= (uint32_t)(mode_bits << (4 * pin)) ;

	} else if (pin <= 15) {
		GPIOx->CRH |= (uint32_t)(mode_bits << (4 * (pin - 7))) ;

	} else {
		return -1 ;
	}

	return 0 ;
}


int config_gpio_cnf_bits(GPIO_TypeDef * GPIOx ,uint8_t pin ,uint8_t cnf_bits)
{
	uint8_t bit_shift ;

	if (pin <= 7) {
		bit_shift = (4 * pin) + 2 ;
		GPIOx->CRL |= (uint32_t)(cnf_bits << bit_shift) ;

	} else if (pin <= 15) {
		bit_shift = (4 * (pin - 7)) + 2 ;
		GPIOx->CRH |= (uint32_t)(cnf_bits << bit_shift) ;

	} else {
		return -1 ;
	}

	return 0 ;
}

void gpio_pin_mode(GPIO_TypeDef * GPIOx ,uint8_t pin ,uint8_t pin_mode)
{
	if (pin_mode == OUTPUT) {
		config_gpio_mode_bits(GPIOx ,pin ,MODE_OUTPUT_50M) ;
		config_gpio_cnf_bits(GPIOx ,pin ,ALT_OUT_PUSHPULL) ;

	} else {
		config_gpio_mode_bits(GPIOx ,pin ,MODE_INPUT) ;
	}
}



void gpio_pin_toggle(GPIO_TypeDef * GPIOx ,uint8_t pin)
{
	GPIOx->ODR ^= (1 << pin)	; /* toggle PC13 */
}

