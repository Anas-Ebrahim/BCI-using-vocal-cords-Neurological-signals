/*
 * Debouncing_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#include "Types.h"
#include "Debouncing_Config.h"
#include "DIO_Private.h"
#include "DIO_config.h"
#include "DIO_interface.h"

 /*
extern u8 u8_DebounceSenceHigh (u8 Debounce_u8Sample)
{
	static u8 Debounce_u8Samples[Debounce_u8Num_Samples];
	static u8 Debounce_u8Index = 0;
	static u8 LastDebounceResult = 0;
	u8 Debounce_u8Counter,Debounce_u8AndTerm = Debounce_u8Sample;
	u8 Debounce_u8OrTerm = Debounce_u8Sample;

	Debounce_u8Samples[Debounce_u8Index++] = Debounce_u8Sample;
	if (Debounce_u8Index >= Debounce_u8Num_Samples)
	{
		Debounce_u8Index = 0;
	}
	else{}
	for ( Debounce_u8Counter = 1; Debounce_u8Counter < Debounce_u8Num_Samples; Debounce_u8Counter++)
	{
		Debounce_u8AndTerm &= Debounce_u8Samples[Debounce_u8Counter];
		Debounce_u8OrTerm  |= Debounce_u8Samples[Debounce_u8Counter];
	}
	return (LastDebounceResult = (LastDebounceResult & Debounce_u8OrTerm)  | Debounce_u8AndTerm );
}
*/
///*
extern u8 u8_DebounceSenceHigh (u8 Debounce_u8Sample,u8 Debounce_u8HighOrLow)
{
	static u8 SampleB = 0;
	static u8 SampleC = 0;
	static u8 LastDebounceResult = 0;

	if(LastDebounceResult  == Debounce_u8HighOrLow){LastDebounceResult=~LastDebounceResult;}

	LastDebounceResult = (LastDebounceResult & (Debounce_u8Sample | SampleB | SampleC)) | (Debounce_u8Sample & SampleB & SampleC);
	SampleC = SampleB;
	SampleB = Debounce_u8Sample;
	//Counter++;
	//if(Counter>4)Counter=0;
	return LastDebounceResult;
}
//*/
