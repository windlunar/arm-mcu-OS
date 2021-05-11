
#ifndef _COMMON_H_
#define _COMMON_H_

#include "../core/stm32f10x.h"

#define SET_SINGLE_BIT(reg ,bit)    \
        do {reg |= (uint32_t)(1 << bit) ;} \
        while(0)



#define CLEAR_SINGLE_BIT(reg ,bit)    \
        do {reg &= ~((uint32_t)(1 << bit)) ;} \
        while(0)

#define TRUE    (1)
#define FALSE   (0)
#define NULL    (0)

#endif
