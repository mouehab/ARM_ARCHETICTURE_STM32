 /******************************************************/
/* Author  : Muhammed Ehab                             */
/* Date    : 18/8/2020                                 */
/* File    : RCC_PROGRAM                               */
/* Version : V01                                       */
/*******************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_int.h"
#include "RCC_priv.h"
#include "RCC_confg.h"

void RCC_voidInitSysClock(void)
{
	#if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR   = 0x00010000; /* Enable HSE with no bypass */
		RCC_CFGR = 0x00000001;
		
	#elif   RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0x00050000; /* Enable HSE with bypass */
		RCC_CFGR = 0x00000001;
		
	#elif   RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0x00000081; /* Enable HSI + Trimming = 0 */
		RCC_CFGR = 0x00000000;
	
	#elif   RCC_CLOCK_TYPE == RCC_PLL
		#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
	
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
		
		#endif
	
	#else
		#error("You chosed Wrong Clock type")
	#endif
}

void RCC_voidEnableClock(u8 copy_u8BusID, u8 copy_u8PerID)
{
    if (copy_u8PerID <= 31)
    {
        switch (copy_u8BusID)
        {
        case RCC_AHB:
             SET_BIT(RCC_AHBENR, copy_u8PerID);
            break;
        case RCC_APB1:
             SET_BIT(RCC_APB1ENR, copy_u8PerID);
            break;
        case RCC_APB2:
             SET_BIT(RCC_APB2ENR, copy_u8PerID);
            break;
        default:
            break;
        }
    }
    else
    {
        /*Return Error*/
    }
}
void RCC_voidDisableClock(u8 copy_u8BusID, u8 copy_u8PerID)
{
    if (copy_u8PerID <= 31)
    {
        switch (copy_u8BusID)
        {
        case RCC_AHB:
             CLR_BIT(RCC_AHBENR, copy_u8PerID);
            break;
        case RCC_APB1:
             CLR_BIT(RCC_APB1ENR, copy_u8PerID);
            break;
        case RCC_APB2:
             CLR_BIT(RCC_APB2ENR, copy_u8PerID);
            break;
        default:
            break;
        }
    }
    else
    {
        /*Return Error*/
    }
}