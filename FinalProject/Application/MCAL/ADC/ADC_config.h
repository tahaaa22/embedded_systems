/*
 * ADC_config.h
 *
 * Created: 9/10/2024 5:10:09 PM
 *  Author: youss
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/* Single Ended Input Channel */
#define ADC0_     0
#define ADC1_     1
#define ADC2_     2
#define ADC3_     3
#define ADC4_     4
#define ADC5_     5
#define ADC6_     6
#define ADC7_     7

/* Division Factor */
#define  _2PRESCALER      1
#define  _4PRESCALER      2
#define  _8PRESCALER      3
#define  _16PRESCALER     4
#define  _32PRESCALER     5
#define  _64PRESCALER     6
#define  _128PRESCALER    7

/* ADC Interrupt Enable */
#define INT_DISABLE       0
#define INT_ENABLE        1

/* Trigger Source */
#define Free_Running_mode           0
#define Analog_Comparator           1
#define External_Interrupt_Request  2
#define TIM0_CTC                    4
#define TIM0_OVF                    5
#define TIM1_CTC_CHANNEL_B          6
#define TIM1_OVF                    7
#define TIM1_ICU                    8

#endif /* ADC_CONFIG_H_ */