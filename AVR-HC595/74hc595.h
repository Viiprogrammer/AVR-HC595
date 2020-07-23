#ifndef SHIFTREG_H
#define SHIFTREG_H
 void ShiftRegisterInit();
 void ShiftRegisterSend(void);
 void ShiftDigitalWrite(int pin, int lvl, int number);
 void ShiftDigitalWritePort(int port, int number);
 char ShiftDigitalGetPort(int number);
 void strobLatch();
 /*
   USE_HARDWARE_SPI 1 - Hardware SPI
   USE_HARDWARE_SPI 0 - Soft SPI
 */
 #define USE_HARDWARE_SPI 0 
 
 #define DATA 2 //DS Pin
 #define SCK 4 //SH_CP (SLK) Pin
 #define LATCH 3 //ST_CP (LATCH) Pin

 #define DATA_DDR DDRB //DS DDR
 #define SCK_DDR DDRB //SH_CP (SLK) DDR
 #define LATCH_DDR DDRB //ST_CP (LATCH) DDR

 #define DATA_PORT PORTB //DS PORT
 #define SCK_PORT PORTB //SH_CP (SLK) PORT
 #define LATCH_PORT PORTB //ST_CP (LATCH) PORT
 

 #define BYTE_ORDER 1
 
 //Count of connected shift register
 #define HC595_COUNT 2
 
 #define HIGH 1
 #define LOW 0
 
#endif //SHIFTREG_H