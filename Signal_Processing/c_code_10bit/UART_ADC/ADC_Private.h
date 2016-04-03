/*
 * ADC_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/*Comment!:ADMUX,ADCSRA,ADCH And ADCL address  */
#define ADMUX_Address	(0x27)
#define ADCSRA_Address	(0x26)
#define ADCH_Address	(0x25)
#define ADCL_Address	(0x24)

typedef union
	{
			struct
			{
				u8 MUX0 :1 ;
				u8 MUX1 :1 ;
				u8 MUX2 :1 ;
				u8 MUX3 :1 ;
				u8 MUX4 :1 ;
				u8 ADLAR:1 ;
				u8 REFS0:1 ;
				u8 REFS1:1 ;
			};
	}ADMUX_Reg;

#define ADMUX		(*(volatile ADMUX_Reg *) ADMUX_Address)
#define ADMUX_MUX0 	ADMUX.MUX0
#define ADMUX_MUX1 	ADMUX.MUX1
#define ADMUX_MUX2 	ADMUX.MUX2
#define ADMUX_MUX3 	ADMUX.MUX3
#define ADMUX_MUX4 	ADMUX.MUX4
#define ADMUX_ADLAR	ADMUX.ADLAR
#define ADMUX_REFS0	ADMUX.REFS0
#define ADMUX_REFS1	ADMUX.REFS1

#define ADMUX_Register		(*(volatile u8 *) ADMUX_Address)

#define	MUX0_0  	0
#define	MUX1_1 		1
#define	MUX2_2  	2
#define	MUX3_3 		3
#define	MUX4_4  	4
#define	ADLAR_5		5
#define	REFS0_6 	6
#define	REFS1_7		7

#define	ADC_u8External  ((1<<REFS0_6)|(0<<REFS1_7))
#define ADC_u8Internal  ((1<<REFS0_6)|(1<<REFS1_7))
#define ADC_u8AREF  	((0<<REFS0_6)|(0<<REFS1_7))

	typedef union
		{
				struct
				{
					u8 ADPS0 :1 ;
					u8 ADPS1 :1 ;
					u8 ADPS2 :1 ;
					u8 ADIE  :1 ;
					u8 ADIF  :1 ;
					u8 ADATE :1 ;
					u8 ADSC  :1 ;
					u8 ADEN	 :1 ;
				};
		}ADCSRA_Reg;

#define ADCSRA				(*(volatile ADCSRA_Reg *) ADCSRA_Address)
#define ADCSRA_ADPS0		ADCSRA.ADPS0
#define ADCSRA_ADPS1		ADCSRA.ADPS1
#define ADCSRA_ADPS2		ADCSRA.ADPS2
#define ADCSRA_ADIE 		ADCSRA.ADIE
#define ADCSRA_ADIF 		ADCSRA.ADIF
#define ADCSRA_ADATE		ADCSRA.ADATE
#define ADCSRA_ADSC 		ADCSRA.ADSC
#define ADCSRA_ADEN			ADCSRA.ADEN

#define ADCSRA_Register				(*(volatile u8 *) ADCSRA_Address)

#define ADCH 	*((volatile u8*)ADCH_Address)
#define ADCL 	*((volatile u8*)ADCL_Address)


#define		ADC_u8Channel_0		0
#define		ADC_u8Channel_1		1
#define		ADC_u8Channel_2		2
#define		ADC_u8Channel_3		3
#define		ADC_u8Channel_4		4
#define		ADC_u8Channel_5		5
#define		ADC_u8Channel_6		6
#define		ADC_u8Channel_7		7


#define		ADC_u8LeftAdjusted	1
#define		ADC_u8RightAdjusted	0


#define		ADC_u8EnableADC			1
#define		ADC_u8DisableADC		0

#define		ADC_u8On		0
#define		ADC_u8Off		1

#define		ADC_u8Bit8		0
#define		ADC_u8Bit10		1

#define		ADPS0_0		0
#define		ADPS0_1		1
#define		ADPS0_2		2

#define 	ADC_u8Factor128		(1<<ADPS0_0 | 1<<ADPS0_1 | 1<<ADPS0_2)
#define 	ADC_u8Factor64		(0<<ADPS0_0 | 1<<ADPS0_1 | 1<<ADPS0_2)
#define 	ADC_u8Factor32		(1<<ADPS0_0 | 0<<ADPS0_1 | 1<<ADPS0_2)
#define 	ADC_u8Factor16		(0<<ADPS0_0 | 0<<ADPS0_1 | 1<<ADPS0_2)
#define 	ADC_u8Factor8		(1<<ADPS0_0 | 1<<ADPS0_1 | 0<<ADPS0_2)
#define 	ADC_u8Factor4		(0<<ADPS0_0 | 1<<ADPS0_1 | 0<<ADPS0_2)
#define 	ADC_u8Factor2		(1<<ADPS0_0 | 0<<ADPS0_1 | 0<<ADPS0_2)

#define		ADC_u8StartConversion			1
#define		ADC_u8NotCompleteConversion		0
#define		ADC_u8Clear						1
#endif /* ADC_PRIVATE_H_ */
