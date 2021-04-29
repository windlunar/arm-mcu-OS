/**
 * Implement By Allen.YY.Lin
 * 
 */ 

#ifndef _COMMON_H_
#define _COMMON_H_

#include "../core/stm32f10x.h"

#define SET_SINGLE_BIT(reg ,bit)    \
        do {reg |= (1 << bit) ;} \
        while(0)



#define CLEAR_SINGLE_BIT(reg ,bit)    \
        do {reg &= ~(1 << bit) ;} \
        while(0)


#endif
