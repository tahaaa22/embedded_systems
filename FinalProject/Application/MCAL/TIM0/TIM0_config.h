/*
 * TIM0_config.h
 *
 * Created: 9/13/2024 9:18:14 PM
 *  Author: youss
 */ 


#ifndef TIM0_CONFIG_H_
#define TIM0_CONFIG_H_
/* Section: Includes */

/* Section: Macro Declaration */

/* TIM0 Modes */
#define OVF_MODE    0
#define PWM_MODE    1
#define CTC_MODE    2
#define FAST_PWM    3

/* Clock Select */
#define  NO_CLK_SOURCE     0
#define  NO_PRESCALING     1					   
#define  _8PRESCALER_      2
#define  _64PRESCALER_     3
#define  _256PRESCALER     4
#define  _1024PRESCALER    5
#define EXT_CLK_FALLING    6
#define EXT_CLK_RISING     7


/* Section: Macro Function Declaration */


/* Section: Data Type Declaration*/


/* Section: Function Declaration */





#endif /* TIM0_CONFIG_H_ */