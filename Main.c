
#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"
#define ON 1

int main(void)
{
	uint16_t Temperature, ADCchannel=0;
	char TempType;
	USARTInit(); 
	while(1){
		uint8_t Status;
		Status=StatusOfLedActuator();
		if(Status==ON){
			Temperature=ReadADC(ADCchannel); 
    	    TempType=GeneratePWM(Temperature);
			USARTWriteString(TempType);
	}
	return 0;
}
}

