/*
 * ADC_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*********************************************************************/
/*************************Public Functions****************************/
/*********************************************************************/

/*Comment!: ADC Init */
extern void ADC_VoidInit(void);
/********************************************************/

/*Comment!: ADC Enable */
extern void ADC_VoidEnable(void);
/********************************************************/

/*Comment!: ADC Disable */
extern void ADC_VoidDisable(void);
/********************************************************/

/*Comment!: Read one Channel Value */
extern u16 ADC_u16ReadChannel(u8 Channel );
/********************************************************/
/*Comment!: Read one Channel Value */
/*Range!: Group:Group(1~2)*/
//extern u16 ADC_u16ReadGroup(u8 Group );

#endif /* ADC_INTERFACE_H_ */
