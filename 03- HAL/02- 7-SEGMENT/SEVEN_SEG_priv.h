/******************************************************/
/* Author  : Muhammed Ehab                            */
/* Date    : 24/8/2020                                */
/* File    : SEVEN_SEG_PRIVATE                        */
/* Version : V01                                      */
/******************************************************/
#ifndef SEVEN_SEG_PRIV_H
#define SEVEN_SEG_PRIV_H


typedef struct 
{
u8 u8Pin_A_PORT ;	
u8 u8Pin_A ;
u8 u8Pin_B_PORT ;	
u8 u8Pin_B ;
u8 u8Pin_C_PORT ;	
u8 u8Pin_C ;
u8 u8Pin_D_PORT ;	
u8 u8Pin_D ;
u8 u8Pin_E_PORT ;	
u8 u8Pin_E ;
u8 u8Pin_F_PORT ;	
u8 u8Pin_F ;
u8 u8Pin_G_PORT ;	
u8 u8Pin_G ;
u8 u8Pin_CM_PORT ;	
u8 u8Pin_CM ;
}STR_7SEG ;

extern STR_7SEG str7SegCfg[MAX_NB_OF_7SEG];













#endif