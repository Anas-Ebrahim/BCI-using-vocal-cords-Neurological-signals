/*
 * Timer_Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*Comment Choose your Prescaler*/
/*Range: Timer_u8ADPSPrescalerBits : Timer_u8Factor(2-4-8-16-32-64-128)*/
//Timer_u8(NoClockSource-NoPrescaler-Factor8-Factor64-Factor256-Factor1024-ExternalClockFallingEdge-ExternalClockRisingEdge)
#define Timer_u8Prescalir   Timer_u8Factor1024


/*Comment :Choose enable or disable Interrupt */
/*Range: Timer_u8EnableOverFlowInterrpt or Timer_u8DisEnableOverFlowInterrpt */
#define Timer_u8Interrupt	Timer_u8DisEnableOverFlowInterrpt

#endif /*TIMER_CONFIG_H_*/
