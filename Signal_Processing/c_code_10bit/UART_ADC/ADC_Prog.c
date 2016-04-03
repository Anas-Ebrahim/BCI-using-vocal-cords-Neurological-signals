/*
 * ADC_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */
#include "Types.h"
#include "DIO_Private.h"
#include "DIO-utilites.h"
#include "ADC_Private.h"
#include "ADC_config.h"
#include "ADC_interface.h"



/*******************************ADC_VoidInit***********************************/
extern void ADC_VoidInit(void)
{
	ADMUX_Register=ADC_u8ADMUXVoltage;
	ADCSRA_Register=ADC_u8ADPSPrescalerBits;
	ADC_VoidEnable();
}
/*******************************ADC_VoidEnable***********************************/
extern void ADC_VoidEnable(void)
{
	ADCSRA_ADEN=ADC_u8EnableADC;
}
/*******************************ADC_VoidDisable***********************************/
extern void ADC_VoidDisable(void)
{
	ADCSRA_ADEN=ADC_u8DisableADC;
}
/*******************************ADC_u16ReadChannel***********************************/
extern u16 ADC_u16ReadChannel(u8 Channel )
{
	u16 ADC_u16ReadADC;
	u8 Local_u8LowBit;

	ADMUX_Register=(ADMUX_Register&0xF0)|Channel; // selecting channel

	#if ADC_u8Channel8_10==ADC_u8Bit8
			ADMUX_ADLAR=ADC_u8LeftAdjusted;
			ADCSRA_ADSC=ADC_u8StartConversion;
			while(ADCSRA_ADIF==ADC_u8NotCompleteConversion);
			ADC_u16ReadADC=ADCH;
	#elif ADC_u8Channel8_10==ADC_u8Bit10
			#if ADC_u8ADLARAdjusted==ADC_u8LeftAdjusted
				ADMUX_ADLAR=ADC_u8LeftAdjusted;
				ADCSRA_ADSC=ADC_u8StartConversion;
				while(ADCSRA_ADIF==ADC_u8NotCompleteConversion);
				Local_u8LowBit=ADCL;
				ADC_u16ReadADC=ADCH << 2 | Local_u8LowBit >> 6;
				//PORTD=ADC_u16ReadADC>>8;
			#elif ADC_u8ADLARAdjusted==ADC_u8RightAdjusted
				ADMUX_ADLAR=ADC_u8RightAdjusted;
				ADCSRA_ADSC=ADC_u8StartConversion;
				while(ADCSRA_ADIF==ADC_u8NotCompleteConversion);
				Local_u8LowBit=ADCL;
				ADC_u16ReadADC=ADCH << 8 | Local_u8LowBit ;
				//PORTB=Local_u8LowBit;
				//PORTC=ADCH;
			#endif
    #endif
	//ADCSRA_ADIF=ADC_u8Clear;

	return ADC_u16ReadADC;
}
