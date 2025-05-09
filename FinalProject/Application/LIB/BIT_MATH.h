/*
* @file: BIT_MATH.h
* @author: Youssef Bassem
* @brief: Contains Function Like MACROS for Masking Bits
* @date: 9/8/2024
*/
#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define SET_BIT(REG,BIT_NUM)	(REG|=(1<<BIT_NUM))
#define CLR_BIT(REG,BIT_NUM)	(REG&=~(1<<BIT_NUM))
#define TOGGLE_BIT(REG,BIT_NUM) (REG^=(1<<BIT_NUM))
#define GET_BIT(REG,BIT_NUM)	((REG>>BIT_NUM)&1)

#endif