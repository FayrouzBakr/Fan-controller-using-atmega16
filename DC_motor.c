/*
 * DC_motor.c
 *
 *  Created on: Oct 12, 2021
 *      Author: Fayrouz
 */


#include "common_macros.h" /* To use the macros like SET_BIT */
#include "DC_motor.h"
#include "gpio.h"
#include "std_types.h"

extern void PWM_Timer0_Start(uint8 duty_cycle);


/*
 * Description :
 * The Function responsible for setup the direction for
 the two motor pins through the GPIO driver.
 *Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN1, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN2, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN_EN, PIN_OUTPUT);
	GPIO_writePin(DC_MOTOR_PORT , DC_MOTOR_PIN1 , LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_PORT ,  DC_MOTOR_PIN2,  LOGIC_LOW);

}
	/*
	 * Description :
	 * The function responsible for rotate the DC Motor CW/ or A-CW
 or stop the motor based on the state input state value.
	 *Send the required duty cycle to the PWM driver based on the required speed value.
	 */
	void DcMotor_Rotate(DcMotor_State state,uint8 speed)
	{
		//uint8 duty_cycle =(speed/100)*255;
		PWM_Timer0_Start(speed);

		switch (state)
		{
		case A_CW:
			GPIO_writePin( DC_MOTOR_PORT, DC_MOTOR_PIN1 ,LOGIC_LOW );
			GPIO_writePin( DC_MOTOR_PORT, DC_MOTOR_PIN2 , LOGIC_HIGH);
			break;
		case CW:
			GPIO_writePin( DC_MOTOR_PORT, DC_MOTOR_PIN1 ,LOGIC_HIGH );
			GPIO_writePin( DC_MOTOR_PORT, DC_MOTOR_PIN2 , LOGIC_LOW);
			break;
		case stop:
			GPIO_writePin( DC_MOTOR_PORT, DC_MOTOR_PIN1 ,LOGIC_LOW );
			GPIO_writePin( DC_MOTOR_PORT, DC_MOTOR_PIN2 , LOGIC_LOW);
			break;
		}


	}
