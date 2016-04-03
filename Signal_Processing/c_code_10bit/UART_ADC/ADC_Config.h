/*
 * ADC_Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*comment: ADMUX (ADC Multiplexer And Selection Register)
 * REFS[0:1] bits determine the source of reference voltage whether it is internal or the external voltage source connected to AREF pin
 */
/*
REFS1 REFS0		 	Voltage Reference Selection
 0 		0 			AREF, Internal Vref turned off
 0 		1 			AVCC with external capacitor at AREF pin
 1 		0 			Reserved//not used
 1 		1 			Internal 2.56V Voltage Reference with external capacitor at AREF pin
*/
/*Range:ADC_u8Voltage :ADC_u8External or ADC_u8Internal or ADC_u8AREF*/
#define 	ADC_u8ADMUXVoltage		ADC_u8External
 /*
 * MUX[4:0] bits are used to select between the channels which will provide data to ADC for conversion*/
 /* Range: ADC_u8WhichChannel from ADC_u8Channel_0(0~7)*/
 #define 	ADC_u8WhichChannel	    ADC_u8Channel_0

 /*  ADLAR bit when set to 1 gives the left adjusted result in data registers ADCH and ADCL.*/
 /* If ADLAR=0, data is right adjusted and if ADLAR=1, data is left adjusted.  Always read ADCL first
  * and then ADCH. In cases where the 8-bit precision is enough set the ADLAR bit to 1 to left adjust the data and
  * read only the ADCH data register.
  * Range: ADC_u8Adjusted : ADC_u8LeftAdjusted or ADC_u8RightAdjusted*/
/* Range: ADC_u8ADLARAdjusted: ADC_u8LeftAdjusted or ADC_u8RightAdjusted*/
#define 	ADC_u8ADLARAdjusted		ADC_u8RightAdjusted

/***************************ADCSRA*********************************************/
/*comment: ADCSRA (ADC Control and Status Register)*/
/*ADEN: ADC Enable bit, this bit must be set to 1 for turning ADC on.*/
 /* Range: ADC_u8StatusADC:ADC_u8EnableADC or ADC_u8DisableADC */
// #define 	ADC_u8ADENStatusADC		ADC_u8EnableADC
 /*
 *ADSC: ADC Start Conversion bit, this bit is set to 1 to start ADC conversion, as soon as conversion is completed this bit is set back to 0 by the hardware.*/
 /* Range: ADC_u8StartConversion :ADC_u8ON or ADC_u8Off */
 //#define 	ADC_u8ADSCStartConversion		ADC_u8On

/*
 *ADATE: ADC Auto Trigger Enable, this bit is set to 1 to enable auto triggering of ADC conversion.*/
 /* Range: ADC_u8StartConversion :ADC_u8Off or ADC_u8ON */
 #define 	ADC_u8ADATEAutoTrigger		ADC_u8Off

/*Range: ADIF: ADC Interrupt Flag, this bit is set to 1 when ADC conversion gets complete.*/
#define 	ADC_u8ADIFInterruptFlag		ADC_u8Off

 /*Range:
 *ADPS[0:2]: ADC Prescaler bits, these bits are used to set the ADC clock frequency, the configuration of these bits determine
 *the division factor by which the microcontroller clock frequency is divided to get the ADC clock frequency. The figure above
 *shows the prescaler bit values for respective division factor.
 *The ADC clock frequency must lie somewhere between 50 KHz to 200 KHz.
 * ADPS2   ADPS1 		ADPS0 	Division Factor
	0 		  0 		  0 		  2
	0 		  0 		  1 		  2
	0 		  1 		  0 		  4
	0 		  1 		  1 		  8
	1 		  0 		  0 		  16
	1 		  0 		  1 		  32
	1 		  1 		  0 		  64
	1 		  1 		  1 		  128
 * */
/*Range: ADC_u8ADPSPrescalerBits : ADC_u8Factor(2-4-8-16-32-64-128)*/
#define 	ADC_u8ADPSPrescalerBits		ADC_u8Factor128

/************************************************************************/
/*
			 VIN * 1024
ADC(value)=-----------------
			   VREF
*/
/*comment: ADC_u8Channel8_10*/
/*Range: ADC_u8ADPSPrescalerBits : ADC_u8Bit8 or ADC_u8Bit10*/
#define 	ADC_u8Channel8_10		ADC_u8Bit10

/*comment: ADC_u8Mode*/
/*Range: ADC_u8Mode : ADC_u8SingleShot or ADC_u8Bit10*/
//#define 	ADC_u8Channel8_10		ADC_u8Bit8




#endif /* ADC_CONFIG_H_ */



