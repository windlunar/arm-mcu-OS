/**
 * Implement by Allen.YY.Lin
 */ 

#include "gpio.h"
#include "../lib/common.h"


void gpio_clk_enable(void)
{
	// Enable clocks for GPIOA ,GPIOB ,GPIOC ports  
	SET_BIT(RCC->APB2ENR ,RCC_APB2ENR_IOPAEN) ;
	SET_BIT(RCC->APB2ENR ,RCC_APB2ENR_IOPBEN) ;
	SET_BIT(RCC->APB2ENR ,RCC_APB2ENR_IOPCEN) ;
}



int config_gpio_mode_bits(GPIO_TypeDef * GPIOx ,uint8_t pin ,uint8_t mode_bits)
{
	if (pin <= 7) {
		// clear original bit first
		GPIOx->CRL &= (uint32_t)~(1 << (4 * pin)) ;
		
		GPIOx->CRL |= (uint32_t)(mode_bits << (4 * pin)) ;

	} else if (pin <= 15) {
		// clear bit first
		GPIOx->CRH &= (uint32_t)~(1 << (4 * (pin - 8))) ;
		
		GPIOx->CRH |= (uint32_t)(mode_bits << (4 * (pin - 8))) ;

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
		
		// clear bit first
		GPIOx->CRL &= (uint32_t)~(1 << bit_shift) ;
		
		GPIOx->CRL |= (uint32_t)(cnf_bits << bit_shift) ;

	} else if (pin <= 15) {
		bit_shift = (4 * (pin - 8)) + 2 ;
		
		// clear bit first
		GPIOx->CRH &= (uint32_t)~(1 << bit_shift) ;
		
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
		config_gpio_cnf_bits(GPIOx ,pin ,GPO_PUSH_PULL) ;

	} else {
		config_gpio_mode_bits(GPIOx ,pin ,MODE_INPUT) ;
	}
}



void gpio_pin_toggle(GPIO_TypeDef * GPIOx ,uint8_t pin)
{
	GPIOx->ODR ^= (1 << pin)	;
}



int gpio_pin_write(GPIO_TypeDef *GPIOx ,uint8_t pin ,uint32_t write)
{
	// High
	if (write == HIGH)
		GPIOx->ODR |= (1 << pin) ;
	
	// low
	else if(write == LOW)
		GPIOx->ODR &= ~(1 << pin) ;
	
	else
		return -1 ;
	
	return 0 ;
}
