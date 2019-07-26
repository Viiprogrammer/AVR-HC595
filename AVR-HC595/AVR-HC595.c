/*
 * AVR_HC595.c
 *
 * Created: 27.07.2019 0:21:56
 *  Author: Maxim
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "74hc595.h"

int main(void)
{
	ShiftRegisterInit();
    while(1)
    {
        for(int i = 0; i < 2; i++){
		  for (int b = 0; b < 8; b++)
		  {
			  ShiftDigitalWrite(b, HIGH, i);
			  _delay_ms(300);
		  }
		}
		for(int i = 0; i < 2; i++){
		  for (int b = 0; b < 8; b++)
		  {
			 ShiftDigitalWrite(b, LOW, i);
			 _delay_ms(300);
		  }
		}
    }
}