/******************************************************/
/* Author  : Muhammed Ehab                            */
/* Date    : 18/8/2020                                */
/* File    : DIO_PROGRAM                              */
/* Version : V01                                      */
/******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void MGPIO_VidSetPinDirection( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Mode ){

	switch(Copy_u8Port)
	{
	case GPIOA:

		if(Copy_u8Pin <= 7 )
		{//low
			
			//RESET THE REGISTER BY BITWISE ANDING WITH ~(0b1111)
			GPIOA_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ));// R M W

			//SHIFTING THE MODE YOU NEED TO APPLY TO THE ACCURATE BITS IN CRL RIGESTIR
			GPIOA_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );

		}
		else if(Copy_u8Pin <=15 )
		{//high

			/*TO RESET THE COUNTER OF THE RIGESTER BITS(if the bin is 9 for example, 
			its pins would be in the 9-8 = 1(*4)= second 4 bits in the register */
			Copy_u8Pin = Copy_u8Pin - 8;

			//RESET THE REGISTER BY BITWISE ANDING WITH ~(0b1111)
			GPIOA_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );

			//SHIFTING THE MODE YOU NEED TO APPLY TO THE ACCURATE BITS IN CRH RIGESTIR
			GPIOA_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );
		}

		break;

	case GPIOB:

		if(Copy_u8Pin <= 7 )
		{//low

			//RESET THE REGISTER BY BITWISE ANDING WITH ~(0b1111)
			GPIOB_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W

			//SHIFTING THE MODE YOU NEED TO APPLY TO THE ACCURATE BITS IN CRL RIGESTIR
			GPIOB_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;

		}
		else if(Copy_u8Pin <=15 )
		{//high

			/*TO RESET THE COUNTER OF THE RIGESTER BITS(if the bin is 9 for example, 
			its pins would be in the 9-8 = 1(*4)= second 4 bits in the register */
			Copy_u8Pin = Copy_u8Pin - 8;
			
			//RESET THE REGISTER BY BITWISE ANDING WITH ~(0b1111)
			GPIOB_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			
			//SHIFTING THE MODE YOU NEED TO APPLY TO THE ACCURATE BITS IN CRH RIGESTIR
			GPIOB_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		break;
	case GPIOC:
		if(Copy_u8Pin <= 7 )
		{//low
			//RESET THE REGISTER BY BITWISE ANDING WITH ~(0b1111)
			GPIOC_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W

			//SHIFTING THE MODE YOU NEED TO APPLY TO THE ACCURATE BITS IN CRL RIGESTIR
			GPIOC_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		else if(Copy_u8Pin <=15 )
		{//high

		/*TO RESET THE COUNTER OF THE RIGESTER BITS(if the bin is 9 for example, 
			its pins would be in the 9-8 = 1(*4)= second 4 bits in the register */
			Copy_u8Pin = Copy_u8Pin - 8;
			
			//RESET THE REGISTER BY BITWISE ANDING WITH ~(0b1111)
			GPIOC_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			
			//SHIFTING THE MODE YOU NEED TO APPLY TO THE ACCURATE BITS IN CRH RIGESTIR
			GPIOC_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		break;
	default :break;
	}


}

void MGPIO_VidSetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Value ){

	switch(Copy_u8Port)
	{
	case GPIOA:
		if( u8Copy_u8Value == HIGH ){

			SET_BIT( GPIOA_ODR , Copy_u8Pin );

		}else if( u8Copy_u8Value == LOW ){
			CLR_BIT(  GPIOA_ODR , Copy_u8Pin );
		}
		break;
		
	case GPIOB:
		if( u8Copy_u8Value == HIGH ){

			SET_BIT( GPIOB_ODR  , Copy_u8Pin );

		}else if( u8Copy_u8Value == LOW ){
			CLR_BIT( GPIOB_ODR  , Copy_u8Pin );
		}
		break;
		
	case GPIOC:
		if( u8Copy_u8Value == HIGH ){

			SET_BIT( GPIOC_ODR , Copy_u8Pin );

		}else if( u8Copy_u8Value == LOW ){
			CLR_BIT( GPIOC_ODR , Copy_u8Pin );
		}
		break;

	}

}

u8   MGPIO_u8GetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin ){

	u8 LOC_u8Result = 0 ;

	switch(Copy_u8Port)
	{
	case GPIOA:
		LOC_u8Result = GET_BIT( GPIOA_IDR , Copy_u8Pin );

		break;
	case GPIOB:

		LOC_u8Result = GET_BIT( GPIOB_IDR , Copy_u8Pin );

		break;
	case GPIOC:

		LOC_u8Result = GET_BIT( GPIOC_IDR , Copy_u8Pin );

		break;
	}
	return LOC_u8Result;
}

