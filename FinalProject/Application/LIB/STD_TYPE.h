/*
* @file: STD_TYPES.h
* @author: Ahmed taha
* @brief: Contains Standard Data Types for all machines
* @date: 9/8/2024
*/

#ifndef _STD_TYPE_H_
#define _STD_TYPE_H_


typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;


typedef  char              s8;
typedef  short             s16;
typedef  int               s32;
typedef  long long         s64;


typedef float              f32;
typedef double             f64;

#define null               (void*)0

typedef enum {False,True}Bool;

#endif