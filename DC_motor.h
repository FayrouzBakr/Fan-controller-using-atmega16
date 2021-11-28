/*
 * DC_motor.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Fayrouz
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DC_MOTOR_PORT PORTB_ID
#define DC_MOTOR_PIN1 PIN0_ID
#define DC_MOTOR_PIN2 PIN1_ID
#define DC_MOTOR_PIN_EN PIN3_ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
	stop,A_CW,CW
}DcMotor_State;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/


/*
 * Description :
 * The Function responsible for setup the direction for
 the two motor pins through the GPIO driver.
 *Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void);

/*
 * Description :
 * The function responsible for rotate the DC Motor CW/ or A-CW
 or stop the motor based on the state input state value.
 *Send the required duty cycle to the PWM driver based on the required speed value.
 */
 void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
