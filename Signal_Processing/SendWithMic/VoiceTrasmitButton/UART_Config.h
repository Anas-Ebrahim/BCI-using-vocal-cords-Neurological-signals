/*
 * UART_Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#define F_CPU_ 			4000000UL
#define USART_BAUDRATE  9600
#define BAUD_PRESCALE (((F_CPU_ / (USART_BAUDRATE * 16UL))) - 1) //normal mode



#endif /* UART_CONFIG_H_ */
