/******************************************************/
/* Author  : Muhammed Ehab                            */
/* Date    : 24/8/2020                                */
/* File    : SEVEN_SEG_CONFIGURATION_EXECUTABLE       */
/* Version : V01                                      */
/******************************************************/

#include "DIO_interface.h"

#include "SEVEN_SEG_config.h"
#include "SEVEN_SEG_priv.h"

STR_7SEG str7SegCfg[MAX_NB_OF_7SEG]=
{
	
   {
        {
         
                GPIOA,
                PIN0 ,
                GPIOA,
                PIN1 ,
                GPIOA,
                PIN2 ,
                GPIOA,
                PIN3 ,
                GPIOA,
                PIN4 ,
                GPIOA,
                PIN5 ,
                GPIOA,
                PIN6 ,
                GPIOA,
                PIN7 
        }, 
    
        {
                GPIOB,
                PIN0 ,
                GPIOB,
                PIN1 ,
                GPIOB,
                PIN2 ,
                GPIOB,
                PIN3 ,
                GPIOB,
                PIN4 ,
                GPIOB,
                PIN5 ,
                GPIOB,
                PIN6 ,
                GPIOB,
                PIN7
        }
 }

    		
};
