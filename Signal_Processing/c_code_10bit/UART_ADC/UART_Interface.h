/*
 * UART_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidSendFromArrayWithNullCh(u8 *Sent);
void UART_voidTransmit( u8 Data );
void UART_voidInit(void);
u8 	 UART_u8Receive( void );

#endif /* UART_INTERFACE_H_ */
