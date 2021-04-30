#ifndef _ACTIVITY1_H_
#define _ACTIVITY1_H_
#define F_CPU 16000000UL 	
#include <avr/io.h>
#include <util/delay.h>

#define LED_ON 	(0x01)			//LED state HIGH 
#define LED_OFF	(0x00)			// LED state LOW 
#define LED_PORT (PORTB)     //LED Port Number 
#define LED_PIN  (PORTB0)   //LED Pin number  
#define BUTTON_SENSOR_PORT  (PORTD) //BUTTON_SENSOR Port number
#define HEATER_SENSOR_PORT  (PORTD)  //HEATER_SENSOR Port number  
#define BUTTON_SENSOR_PIN  (PORTD0)  //BUTTON_SENSOR Pin number  
#define HEATER_SENSOR_PIN  (PORTD1) //HEATER_SENSOR Pin number  
#define BUTTON_SENSOR_ON 	!(PIND & 1<<PD0)	//BUTTON_SENSOR state HIGH 
#define HEATER_SENSOR_ON	!(PIND & 1<<PD1)	// HEATER_SENSOR state HIGH 
#define SET_PORTB0_AS_OUTPUT  DDRB |= (1<<PORTB0)
#define SET_PD0_AND_PD1_AS_PULLUP  PORTD |= (1<<PORTD1)|(1<<PORTD0)
#define SET_PORTD_AS_INPUT  DDRD = 0x00

void ChangeLEDState(uint8_t state);


void SetButtonSensorPin(void);


void SetHeaterSensorPin(void);


void DelayMilliSecond(uint32_t delay_time);


uint8_t StatusOfLedActuator(void);


void InitializePeripherals(void);

#endif /* _ACTIVITY1_H_ */