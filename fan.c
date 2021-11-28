/*
 * fan.c
 *
 *  Created on: Oct 9, 2021
 *      Author: Fayrouz
 */

#include"lcd.h"
#include"lm35_sensor.h"
#include"DC_motor.h"
#include"adc.h"
#include <util/delay.h> /* For the delay functions */

void fan_controller(uint8 temperature);

int main()
{
	LCD_init();
	DcMotor_Init();
	uint8 Temperature;// the temp. we get from the lm35 sensor
	ADC_ConfigType ADC_Config = {INTERNAL,DI8};
	ADC_init(&ADC_Config);
	while (1)
	{
		Temperature=LM35_getTemperature();
		LCD_displayStringRowColumn(0,0,"FAN IS ");
		LCD_displayStringRowColumn(1,0,"temp =");
		fan_controller(Temperature);

	}


}

/*
 * the functoin take the temp converted with adc
 * it stop or rotate the fan (motor) depends on the temp
 * then it display it on lcd
 */

void fan_controller(uint8 temperature)
{




	if (temperature>=120)
	{
		DcMotor_Rotate( CW , 100);
		LCD_displayStringRowColumn(0,10,"ON");
		LCD_moveCursor(1,10);
		LCD_intgerToString(temperature);
		_delay_ms(500);
		LCD_clearScreen();
	}
	else if (temperature>=90)
	{
		DcMotor_Rotate( CW , 75);
		LCD_displayStringRowColumn(0,10,"ON");
		LCD_moveCursor(1,10);
		LCD_intgerToString(temperature);
		_delay_ms(500);
		LCD_clearScreen();
	}
	else if (temperature>=60)
	{
		DcMotor_Rotate( CW, 50);
		LCD_displayStringRowColumn(0,10,"ON");
		LCD_moveCursor(1,10);
		LCD_intgerToString(temperature);
		_delay_ms(500);
		LCD_clearScreen();
	}
	else if (temperature>=30)
	{
		DcMotor_Rotate( CW, 25);
		LCD_displayStringRowColumn(0,10,"ON");
		LCD_moveCursor(1,10);
		LCD_intgerToString(temperature);
		_delay_ms(500);
		LCD_clearScreen();
	}
	else if (temperature<30)
	{
		DcMotor_Rotate( stop, 0);
		LCD_displayStringRowColumn(0,10,"OFF");
		LCD_moveCursor(1,10);
		LCD_intgerToString(temperature);
		_delay_ms(500);
		LCD_clearScreen();
	}


}

