/*
 * Timer_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#include "delay.h"
#include "Timer_Config.h"
#include "Timer_Private.h"
#include "Timer_Interface.h"

static u16 Local_u16TotalTime=0;
/***************************************/
void Timer_VoidInit(void)
{
	TCCR0|=Timer_u8Prescalir;
	// initialize counter
	TCNT0 = 0;
	TIMSK|=Timer_u8Interrupt;
}
/***************************************/
void Timer_VoidStopTimer0(void)
{
	TCCR0|=Timer_u8NoClockSource;
	// initialize counter
	TCNT0 = 0;
}

/***************************************/
//OverFlow EXT0
ISR(__vector_11)
{
	ptr_OverFlow();
}
/***************************************/

extern void ExtInt_voidOverFlowInt0(void (*Local_ptr)(void))
{
	ptr_OverFlow=Local_ptr;
}
/***************************************/

extern u16 Timer_u16Count1mile(void)
{//here will calulate time off what is the time that take by calulate number of
	//Local_u16TotalTime and know how much time it take?
	u16 Local_u16ValueThatReturn=0;
	if(TCNT0 >= (u8)(Timer_u16TimerCounter)+1)//Timer_u16TimerCounter)//1 mile
	{//(u8)(Timer_u16TimerCounter)+1 3mlt u8 +1 3shan hwa ksr w ana msh hinf3 a2arn bksr
		//+1 3shan ygeb elrkm elkber 3la tol y3ny 14.25 lw u8 bs hia5d 14 l2 zwd b2a 3shan tb2a 15
		Local_u16TotalTime++;
		Local_u16ValueThatReturn=Local_u16TotalTime;
		TCNT0=0;
	}
	else;
	return Local_u16ValueThatReturn;
//when prescaler= 8
//	if (tot_overflow >= 1960)  // 500 mile
//			{
//				if (TCNT0 >= 200)
//				{
//					PORTA^=0xff;
//					Timer_u16ResetTotalTime();
//					Timer_u16ResetCounter();
//					tot_overflow=0;
//				}
//			}
}
/***************************************/

extern void Timer_u16ResetTotalTime(void)
{
	Local_u16TotalTime=0;
}
/***************************************/

extern void Timer_u16ResetCounter(void)
{
	TCNT0=0;
}

