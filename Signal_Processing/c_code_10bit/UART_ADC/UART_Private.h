/*
 * UART_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UCSRB_u8Address	(0x2A)
#define UCSRC_u8Address	(0x40)
#define UBRRH_u8Address	(0x20)
#define UBRRL_u8Address	(0x29)
#define UCSRA_u8Address	(0x2B)
#define UDR_u8Address	(0x2C)



#define UDR		(*(volatile u8 *) UDR_u8Address)

#define UCSRB	(*(volatile u8 *) UCSRB_u8Address)
#define RXEN	4
#define TXEN	3

#define UCSRC		(*(volatile u8 *) UCSRC_u8Address)
#define URSEL	7
#define UCSZ0	1
#define UCSZ1	2


#define UBRRL		(*(volatile u8 *) UBRRL_u8Address)
#define UBRRH		(*(volatile u8 *) UBRRH_u8Address)

#define UCSRA		(*(volatile u8 *) UCSRA_u8Address)
#define UDRE	5
#define RXC		7
#endif /* UART_PRIVATE_H_ */













