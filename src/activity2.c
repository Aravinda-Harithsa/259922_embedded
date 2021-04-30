#include "activity1.h"
#include "activity2.h"
#define CONVERSION_IS_INCOMPLETE  ADCSRA & (1<<ADSC)

void InitializeADC()
{
    // SelectReference voltage as = VCC
    ADMUX |= (1<<REFS0);
    //Enable value of  prescaller to 128 Bits and enable ADC
    ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);
}
uint16_t ReadADC(uint8_t channel)
{
    InitializeADC();
    ADMUX &= 0xF8;
    channel &= 0x07;
    ADMUX &= channel;
    ADCSRA |= (1<<ADSC);
    while(CONVERSION_IS_INCOMPLETE);
    ADCSRA|=(1<<ADIF);
    return ADC;
}