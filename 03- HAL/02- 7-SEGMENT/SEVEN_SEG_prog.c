/******************************************************/
/* Author  : Muhammed Ehab                            */
/* Date    : 24/8/2020                                */
/* File    : SEVEN_SEG_PROGRAM                        */
/* Version : V01                                      */
/******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SEVEN_SEG_int.h"
#include "SEVEN_SEG_config.h"
#include "SEVEN_SEG_priv.h"

ERROR_STATUS SvnSeg_enuDisplay(u8 u8SegIndex_Cpy, u8 u8Displayed_Number_Cpy)
{
    ERROR_STATUS enuErrorStatus = OK ;
    #if SEV_MODE == COMMON_ANODE
	    u8 seg[10]= {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
	#else 
	    u8 seg[10]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	#endif
    if(u8SegIndex_Cpy > MAX_NB_OF_7SEG || u8Displayed_Number_Cpy > 9)
	{
		enuErrorStatus = INDEX_OUT_OF_RANGE ;
	} 
    else
    {
        MGPIO_VidSetPinValue(str7SegCfg[u8SegIndex_Cpy].u8Pin_A_PORT, str7SegCfg[u8SegIndex_Cpy].u8Pin_A,
        GET_BIT(seg[u8Displayed_Number_Cpy],0));
        MGPIO_VidSetPinValue(str7SegCfg[u8SegIndex_Cpy].u8Pin_B_PORT, str7SegCfg[u8SegIndex_Cpy].u8Pin_B,
        GET_BIT(seg[u8Displayed_Number_Cpy],1));
        MGPIO_VidSetPinValue(str7SegCfg[u8SegIndex_Cpy].u8Pin_C_PORT, str7SegCfg[u8SegIndex_Cpy].u8Pin_C,
        GET_BIT(seg[u8Displayed_Number_Cpy],2));
        MGPIO_VidSetPinValue(str7SegCfg[u8SegIndex_Cpy].u8Pin_D_PORT, str7SegCfg[u8SegIndex_Cpy].u8Pin_D,
        GET_BIT(seg[u8Displayed_Number_Cpy],3));
        MGPIO_VidSetPinValue(str7SegCfg[u8SegIndex_Cpy].u8Pin_E_PORT, str7SegCfg[u8SegIndex_Cpy].u8Pin_E,
        GET_BIT(seg[u8Displayed_Number_Cpy],4));
        MGPIO_VidSetPinValue(str7SegCfg[u8SegIndex_Cpy].u8Pin_F_PORT, str7SegCfg[u8SegIndex_Cpy].u8Pin_F,
        GET_BIT(seg[u8Displayed_Number_Cpy],5));
        MGPIO_VidSetPinValue(str7SegCfg[u8SegIndex_Cpy].u8Pin_G_PORT, str7SegCfg[u8SegIndex_Cpy].u8Pin_G,
        GET_BIT(seg[u8Displayed_Number_Cpy],6));
        MGPIO_VidSetPinValue(str7SegCfg[u8SegIndex_Cpy].u8Pin_CM_PORT, str7SegCfg[u8SegIndex_Cpy].u8Pin_CM,
        GET_BIT(seg[u8Displayed_Number_Cpy],7));
    }
}