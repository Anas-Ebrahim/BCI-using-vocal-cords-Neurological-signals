/*
 * Timer_Interace.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */
#ifndef TIMER_INTERFAC_H_
#define TIMER_INTERFAC_H_


void Timer_VoidInit(void);
extern void ExtInt_voidOverFlowInt0(void (*Local_ptr)(void));
extern u16 Timer_u16Count1mile(void);
extern void Timer_u16ResetTotalTime(void);
extern void Timer_u16ResetCounter(void);
extern void Timer_VoidStopTimer0(void);

#endif /* TIMER_INTERFAC_H_ */


