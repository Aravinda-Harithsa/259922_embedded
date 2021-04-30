# Activity1, Activity2, Activity3 and Activity4 In Action

|ON|OFF|
|:--:|:--:|
|![image](https://user-images.githubusercontent.com/42568338/116530077-3e468a00-a8fb-11eb-802d-8837b8b27ffe.png)|![image](https://user-images.githubusercontent.com/42568338/116530100-443c6b00-a8fb-11eb-8db3-3f00ee57b6f0.png)|

## Code 
```
while(1){
	uint8_t Status;
	/* Turns LED ON if and only if both switches ButtonSensor and Heater are closed */
	Status=StatusOfLedActuator();
	if(Status==ON){
		Temperature=ReadADC(ADCchannel); /*reads sensor data from ADCChannel*/
		TempType=GeneratePWM(Temperature);/*Generates PWM according to data received from sensor*/
		USARTWriteString(TempType);/*Sends data to serial monitor*/
	}
}
```
