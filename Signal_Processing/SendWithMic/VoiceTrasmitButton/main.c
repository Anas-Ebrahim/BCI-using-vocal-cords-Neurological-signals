/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */
#include "Types.h"
#include "DIO_interface.h"
//#include "DIO_Private.h"
#include "Debouncing_Interface.h"
#include "ADC_interface.h"
#include "Timer_Interface.h"
#include "UART_interface.h"
#include "delay.h"

#define SWPin			8
#define SenceHigh		1
#define SenceLow		0
#define Pressed			1
#define NotPressed		0
#define CheckLed		16

int main (void)
{
	u16 Local_u16ReturnedTime=0;
	u16 UARTADC_u16Val;
	u8 Local_u8PressedBtnFlag=0;
	u8 UARTADC_u8Low=0,UARTADC_u8High=0,Receiver=0,SwPinVar=0;

	DIO_VoidInit();
	ADC_VoidInit();
	UART_voidInit();
	Timer_VoidStopTimer0();//stop timer untill enable timer

	while(1)
	{
		DIO_u8ReadPinVal(SWPin,&SwPinVar);
		if((u8_DebounceSenceHigh(SwPinVar,SenceHigh)==Pressed)&&(Local_u8PressedBtnFlag==NotPressed))
		{
			DIO_u8WritePinVal(CheckLed,SenceHigh );
			Local_u8PressedBtnFlag=1;
			Timer_VoidInit();  /* enable Timer */
			UART_voidTransmit('m');  /* start sending data */
			while (Local_u16ReturnedTime != 2000 || Local_u16ReturnedTime > 2000)
			{
				Receiver=UART_u8Receive();
				if(Receiver=='s')  /* check the received var 's' = start data */
				{
					UARTADC_u16Val=ADC_u16ReadChannel(0);	/*read the converted data from the ADC channel */
					UARTADC_u8Low=(u8)UARTADC_u16Val;       /* store the least sig data */
					UARTADC_u8High=(u8)(UARTADC_u16Val>>8);	/* store the most sig data */
					UART_voidTransmit(UARTADC_u8Low);		/* start send the data frame to octave */
					UART_voidTransmit(UARTADC_u8High);
					UART_voidTransmit('e');					/* end the frame with 'e' */
					Receiver=0;								/* return the receiver val to zero */
		     	}
				else if (Receiver=='r')					/* if data is incorrect */
				{
					UART_voidTransmit(UARTADC_u8Low);		/* start send the data frame to octave */
					UART_voidTransmit(UARTADC_u8High);
					UART_voidTransmit('e');					/* end the frame with 'e' */
					Receiver=0;								/* return the receiver val to zero */
				}
				else;
				Local_u16ReturnedTime=Timer_u16Count1mile();   /* count till 2 sec */
				//PORTC=Local_u16ReturnedTime;
			}
			Timer_u16ResetCounter();
			Timer_u16ResetTotalTime();
			Timer_VoidStopTimer0();
			DIO_u8WritePinVal(CheckLed,SenceLow );
			Local_u16ReturnedTime=0;
			UART_voidTransmit(' ');//
			UART_voidTransmit(' ');//
			UART_voidTransmit('t');//check on t in the third element
		}
		else
		{
			Local_u8PressedBtnFlag=0;
		}
	}
	return 0;
}
