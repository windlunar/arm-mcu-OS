/**
 * Implement by Allen.YY.Lin
 */ 

#ifndef _GPIO_H_
#define _GPIO_H_

#include <stm32f10x.h>


/**
 * PORT Config Register Bits Definition
 * 
 */ 
// Mode bits definition
#define MODE_INPUT              (0)
#define MODE_OUTPUT_10M         (1)
#define MODE_OUTPUT_2M          (2)
#define MODE_OUTPUT_50M         (3)

// When Mode bit is set to output (CNFx bits)
#define GPO_PUSH_PULL           (0)
#define GPO_OPEN_DRAIN          (1)
#define ALT_OUT_PUSHPULL        (2)
#define ALT_OUT_OPEN_DRAIN      (3)


#define OUTPUT      (0)
#define INPUT       (1)
#define LOW      		(0)
#define HIGH       	(1)

void gpio_clk_enable(void) ;
int config_gpio_mode_bits(GPIO_TypeDef * GPIOx ,uint8_t pin ,uint8_t mode_bits) ;
int config_gpio_cnf_bits(GPIO_TypeDef * GPIOx ,uint8_t pin ,uint8_t cnf_bits) ;
void gpio_pin_mode(GPIO_TypeDef * GPIOx ,uint8_t pin ,uint8_t pin_mode) ;
void gpio_pin_toggle(GPIO_TypeDef * GPIOx ,uint8_t pin) ;
int gpio_pin_write(GPIO_TypeDef *GPIOx ,uint8_t pin ,uint32_t write) ;

#endif
