/*
 * ADC_Program.c
 *
 * Created: 13/12/2024 6:02:28 PM
 *  Author: zyade
 */ 

#include "ADC_Interface.h"

void ADC_Initialize_WithoutInterrupt(adc_vref vref, adc_prescaler prescaler) {
	// Set reference voltage
	_ADC_ADMUX = (vref << 6); // Bits 7:6 for VREF

	// Enable ADC, set prescaler, and disable interrupts
	_ADC_ADCSRA = (1 << ADEN) | (prescaler & 0x07); // Bits 2:0 for prescaler
}

void ADC_Initialize_WithInterrupt(adc_vref vref, adc_prescaler prescaler) {
	// Set reference voltage
	_ADC_ADMUX = (vref << 6); // Bits 7:6 for VREF

	// Enable ADC, set prescaler, and enable interrupts
	_ADC_ADCSRA = (1 << ADEN) | (1 << ADIE) | (prescaler & 0x07); // Bits 2:0 for prescaler
}

uint16_t ADC_Read(adc_channel channel)
{
	/*
	1- Create variable for reading
	2- Choose channel to read
	3- Start conversion
	4- Wait until end conversion
	5- Return reading
	*/
	uint16_t ADC_read = 0;
	switch (channel)
	{
		case ADC_channel_0:
		_ADC_ADMUX = 0x40;//0b 010 00000
		break;
		case ADC_channel_1:
		_ADC_ADMUX = 0x41;//0b 010 00001
		break;
		case ADC_channel_2:
		_ADC_ADMUX = 0x42;//0b 010 00010
		break;
		case ADC_channel_3:
		_ADC_ADMUX = 0x43;//0b 010 00011
		break;
		case ADC_channel_4:
		_ADC_ADMUX = 0x44;//0b 010 00100
		break;
		case ADC_channel_5:
		_ADC_ADMUX = 0x45;//0b 010 00101
		break;
		case ADC_channel_6:
		_ADC_ADMUX = 0x46;//0b 010 00110
		break;
		case ADC_channel_7:
		_ADC_ADMUX = 0x47;//0b 0100 0111
		break;
		default:
		_ADC_ADMUX = 0x40;
		break;
	}
	_ADC_ADCSRA |= (1<<ADSC);
	while (get_bit(_ADC_ADCSRA, ADIF) != 1);
	ADC_read = _ADC_DATA;
	return ADC_read;
}