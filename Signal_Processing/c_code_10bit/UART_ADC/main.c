/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */
#include "Types.h"
#include "DIO_Private.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "UART_interface.h"
#include "delay.h"

int main (void)
{
	u8 UARTADC_u8Low,UARTADC_u8High,Receiver;
	u16 UARTADC_u16Val;
	DIO_VoidInit();
	ADC_VoidInit();
	UART_voidInit();
	//PORTB=ADC_u16ReadChannel(0);
	//u8 a[]="ahmed";

	while(1)
	{
		//Delay_ms_Max1s(100);
//		/*
		Delay_ms_Max1s(1);
		Receiver=UART_u8Receive();
		if(Receiver=='s')
		{
			//UART_voidSendFromArrayWithNullCh(a);
			UARTADC_u16Val=ADC_u16ReadChannel(0);
			UARTADC_u8Low=(u8)UARTADC_u16Val;
			UARTADC_u8High=(u8)(UARTADC_u16Val>>8);
			UART_voidTransmit(UARTADC_u8Low);
			//Delay_ms_Max1s(1);
			UART_voidTransmit(UARTADC_u8High);
			//Delay_ms_Max1s(1);
			UART_voidTransmit('e');
			//Delay_ms_Max1s(1);
			Receiver=0;
		}
		else;
		//Delay_ms_Max1s(10);

	//	UART_voidTransmit(ADC_u16ReadChannel(0)); //8bit
		//Delay_ms_Max1s(100);

	}
	return 0;
}
