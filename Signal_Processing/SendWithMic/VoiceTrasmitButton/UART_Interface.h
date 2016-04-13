/*
 * UART_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

extern void UART_voidSendFromArrayWithNullCh(u8 *Sent);
extern void UART_voidTransmit( u8 Data );
extern void UART_voidInit(void);
extern u8 	 UART_u8Receive( void );
extern u8 UART_u8GetUDR( void );
#endif /* UART_INTERFACE_H_ */
