
#ifndef _GPIO_H_
#define _GPIO_H_

#include "../core/stm32f10x.h"


/**
 * PORT Config Register Bits Definition
 * 
 */ 
// Mode bits definition
#define MODE_INPUT              (00)
#define MODE_OUTPUT_10M         (01)
#define MODE_OUTPUT_2M          (10)
#define MODE_OUTPUT_50M         (11)

// When Mode bit is set to output (CNFx bits)
#define GPO_PUSH_PULL           (00)
#define GPO_OPEN_DRAIN          (01)
#define ALT_OUT_PUSHPULL        (10)
#define ALT_OUT_OPEN_DRAIN      (11)


/**
 * CRL pin shift definition
 * 
 */ 
#define PIN_0_MODE_SHIFT         (0)
#define PIN_1_MODE_SHIFT         (4)
#define PIN_2_MODE_SHIFT         (8)
#define PIN_3_MODE_SHIFT         (12)
#define PIN_4_MODE_SHIFT         (16)
#define PIN_5_MODE_SHIFT         (20)
#define PIN_6_MODE_SHIFT         (24)
#define PIN_7_MODE_SHIFT         (28)

#define PIN_0_CNF_SHIFT         (2)
#define PIN_1_CNF_SHIFT         (6)
#define PIN_2_CNF_SHIFT         (10)
#define PIN_3_CNF_SHIFT         (14)
#define PIN_4_CNF_SHIFT         (18)
#define PIN_5_CNF_SHIFT         (22)
#define PIN_6_CNF_SHIFT         (26)
#define PIN_7_CNF_SHIFT         (30)
/**
 * CRH pin shift definition
 * 
 */ 
#define PIN_8_MODE_SHIFT         (0)
#define PIN_9_MODE_SHIFT         (4)
#define PIN_10_MODE_SHIFT         (8)
#define PIN_11_MODE_SHIFT         (12)
#define PIN_12_MODE_SHIFT         (16)
#define PIN_13_MODE_SHIFT         (20)
#define PIN_14_MODE_SHIFT         (24)
#define PIN_15_MODE_SHIFT         (28)

#define PIN_8_CNF_SHIFT         (2)
#define PIN_9_CNF_SHIFT         (6)
#define PIN_10_CNF_SHIFT         (10)
#define PIN_11_CNF_SHIFT         (14)
#define PIN_12_CNF_SHIFT         (18)
#define PIN_13_CNF_SHIFT         (22)
#define PIN_14_CNF_SHIFT         (26)
#define PIN_15_CNF_SHIFT         (30)


void gpio_clk_enable(void) ;
int config_gpio_mode(GPIO_TypeDef * GPIOx ,uint8_t pin ,uint8_t mode_bits) ;
int config_gpio_cnf(GPIO_TypeDef * GPIOx ,uint8_t pin ,uint8_t cnf_bits) ;

#endif
