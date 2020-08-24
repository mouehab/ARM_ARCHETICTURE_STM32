/******************************************************/
/* Author  : Muhammed Ehab                            */
/* Date    : 18/8/2020                                */
/* Version : V01                                      */
/******************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char          u8;
typedef unsigned short int     u16;
typedef unsigned long int       u32;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef float f32;
typedef double f64;
typedef long double f80;
typedef enum {
	INDEX_OUT_OF_RANGE,
	NULL_POINTER,
	OK,
	NOK
	}ERROR_STATUS;


#endif
