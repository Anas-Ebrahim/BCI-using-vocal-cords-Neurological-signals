/*
 * UART_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */
#include "delay.h"
#include "UART_Private.h"
#include "UART_Config.h"
#include "UART_Interface.h"

void UART_voidInit(void)
{
	 /*
	 The UMSEL bit in USART Control and Status Register C (UCSRC) selects between asynchronous and
	 synchronous operation.*/
	 /*
		Double Speed (Asynchronous mode only) is controlled by the U2X found in the UCSRA
		Register. When using Synchronous mode (UMSEL = 1), the Data Direction Register for the XCK
		pin (DDR_XCK) controls whether the clock source is internal (Master mode) or external (Slave
		mode). The XCK pin is only active when using Synchronous mode.
	 */
	 /*Double Speed Operation (U2X):
		The transfer rate can be doubled by setting the U2X bit in UCSRA. Setting this bit only has effect
		for the asynchronous operation. Set this bit to zero when using synchronous operation.
		Setting this bit will reduce the divisor of the baud rate divider from 16 to 8, effectively doubling
		the transfer rate for asynchronous communication. Note however that the receiver will in this
		case only use half the number of samples (reduced from 16 to 8) for data sampling and clock
		recovery, and therefore a more accurate baud rate setting and system clock are required when
		this mode is used. For the Transmitter, there are no downsides.
	 */
	 /*
				fOSC
		fXCK < ------
				  4
   */
   /*
		Before doing a re-initialization with changed baud rate or frame format, be sure that there are no
		ongoing transmissions during the period the registers are changed. The TXC Flag can be used
		to check that the Transmitter has completed all transfers, and the RXC Flag can be used to
		check that there are no unread data in the receive buffer. Note that the TXC Flag must be
		cleared before each transmission (before UDR is written) if it is used for this purpose.
   */
   UCSRB = (1 << RXEN) | (1 << TXEN);   // Turn on the transmission and reception circuitry
   UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); // Use 8-bit character sizes

   UBRRH = (BAUD_PRESCALE >> 8); //25// Load upper 8-bits of the baud rate value into the high byte of the UBRR register
   UBRRL = BAUD_PRESCALE; // Load lower 8-bits of the baud rate value into the low byte of the UBRR register
 }
/**************************************/
void UART_voidTransmit( u8 Data )
{
    /* Wait for empty transmit buffer */
    while(!( UCSRA & (1<<UDRE) ));

    /* Put data into buffer, sends the data */
    UDR = Data;
}
/****************************************/
void UART_voidSendFromArrayWithNullCh(u8 *Sent)
 {
    while(*Sent != '\0')
        {
    		UART_voidTransmit(*Sent++);
        }
 }
/****************************************/
u8 UART_u8Receive( void )
    {
        /* Wait for data to be received */
        while ( !(UCSRA & (1<<RXC)) );
        /* Get and return received data from buffer */
        return UDR;
    }
