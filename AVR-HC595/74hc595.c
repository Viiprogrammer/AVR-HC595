#include <avr/io.h>
#include "74hc595.h"


//Buffer
char ShiftPORT[HC595_COUNT] = {0};

/* 
  Init SPI and I/O pins
*/
void ShiftRegisterInit(){
  	DATA_DDR |= (1<<DATA);
	SCK_DDR |= (1<<SCK);
	LATCH_DDR |= (1<<LATCH);
	
  	DATA_PORT &=~ (1 << DATA);
	SCK_PORT &=~ (1 << SCK);
	LATCH_PORT &=~ (1 << LATCH);
	#if (USE_HARDWARE_SPI == 1) 
	 SPCR = ((1<<SPE)|(1<<MSTR)); //SPI config for Atmega8 if you have problems with hardware SPI change this or use soft SPI
	#endif
}


void strobLatch(){
	LATCH_PORT |= (1 << LATCH);
	LATCH_PORT &=~ (1 << LATCH);
}
/*
  Send data to Shift register
*/
void ShiftRegisterSend(){
	#if (USE_HARDWARE_SPI == 1) 
	for(unsigned int byte = 0; byte < sizeof(ShiftPORT); byte++){
		SPDR = ShiftPORT[byte];
		while(!(SPSR & (1<<SPIF)));
	}
	#else
	
	#if (BYTE_ORDER == 1) 
	for(unsigned int byte = sizeof(ShiftPORT); byte > 0; byte--){
	#else
	  for(unsigned int byte = 1; byte <= sizeof(ShiftPORT); byte++){
	#endif  
	
		unsigned char data = ShiftPORT[byte-1];
		for(unsigned int bit = 0; bit < 8; bit++){
			if(data & 0x80){
				DATA_PORT |= (1 << DATA);
			}else{
				DATA_PORT &=~ (1 << DATA);
			}
			SCK_PORT |= (1 << SCK);
			SCK_PORT &=~ (1 << SCK);
			data <<= 1;
		}
	}
	#endif   
}
/* 
  Set one pin of the shift register 
  Use example:
    ShiftDigitalWrite(4, HIGH, 2);
    This example set pin 4 of №3 shift regisner to HIGH level (numbering from 0)
*/
void ShiftDigitalWrite(int pin, int lvl, int number){
  if(lvl){
    ShiftPORT[number] |= (1 << pin);
  }else{
	ShiftPORT[number] &= ~(1 << pin);
  }
  ShiftRegisterSend();
}
/*
   Write byte to shift register
   Use example: 
   ShiftDigitalWritePort(0xFF, 1);
   This example set all pins of №2 shuft register to HIGH level (numbering from 0)
*/
void ShiftDigitalWritePort(int port, int number){
    ShiftPORT[number] = port;
	ShiftRegisterSend();
}

/*
 Get  actual byte from shift register
 Use example:
  ShiftDigitalGetPort(1);
  This example return actual byte from shift register №2 (numbering from 0)
*/
char ShiftDigitalGetPort(int number){
	 return ShiftPORT[number];
}