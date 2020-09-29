# AVR-HC595
Library for 74hc595 shift register

Use library example: 

```
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
			  strobLatch();
			  _delay_ms(300);
		  }
		}
		for(int i = 0; i < 2; i++){
		  for (int b = 0; b < 8; b++)
		  {
			 ShiftDigitalWrite(b, LOW, i);
			 strobLatch();
			 _delay_ms(300);
		  }
		}
    }
}
```
Example compiled for ATMEGA8

Ru: Пример работы с симуляцией протеус в hc595.pdsprj 

En: Work example with Proteus simulation in hc595.pdsprj

## Описание функций 74hc595.c RU

Функция | Описание | Пример | Описание примера |
| ------------- | ------------- | ------------- | ------------- |
ShiftRegisterInit(void) | Используется для инициализации сдвиговых регистров | ShiftRegisterInit();  | Инициализирует SPI и порты
ShiftRegisterSend(void) | Используется для отправки данных на все сдвиговые регистры | ShiftRegisterSend(); | None
ShiftDigitalWrite(int pin, int lvl, int number) | Запись одного пина | ShiftDigitalWrite(4, HIGH, 2); | Устанавливает 4ю ногу сдвиггового регистра #3  в HIGH уровень (нумерация сдвиговых регистров от нуля 0)
ShiftDigitalWritePort(int port, int number) | Запись данных в весь порт сдвигового регистра | ShiftDigitalWritePort(0xFF, 1); | Устанока всех выводов сдвигового регистра #2 (нумерация сдвиговых регистров от нуля 0) в HIGH записью `FF` в порт
ShiftDigitalGetPort(int number) | Возврат байта порта| ShiftDigitalGetPort(1); | Возвращает актуальную информацию о состоянии порта сдвигового регистра #2 (нумерация сдвиговых регистров от нуля 0)
strobLatch() | Выводит данные на выход регистров | strobLatch(); | -

## Functions description  74hc595.c EN

Function | Description | Example | Example Description |
| ------------- | ------------- | ------------- | ------------- |
ShiftRegisterInit(void) | Used for Init Shift Registers | ShiftRegisterInit();  | Init SPI and I/O pins
ShiftRegisterSend(void) | Used for for send data into all Shift Registers | ShiftRegisterSend(); | None
ShiftDigitalWrite(int pin, int lvl, int number) | Write of one pin  | ShiftDigitalWrite(4, HIGH, 2); | Set pin 4 of #3 (numbering from 0) shift regisner to HIGH level
ShiftDigitalWritePort(int port, int number) | Writing data to shift register port | ShiftDigitalWritePort(0xFF, 1); | Set all pins of #2 (numbering from 0) shift register to HIGH level
ShiftDigitalGetPort(int number) | Return actual byte of port | ShiftDigitalGetPort(1); |  Return actual byte from shift register #2 (numbering from 0)
strobLatch() | Latch shift register(s) | strobLatch(); | -



## Конфигурация 74hc595.h RU 

Define | Описание
| ------------- | ------------- |
USE_HARDWARE_SPI | Если 1 используется хардварный SPI, если 0 то софтварный на указаных портах и пинах
DATA 0 & SCK 3 & LATCH 4 | Пины подключения сдвигового регистра, при USE_HARDWARE_SPI = 1 указать пины хардварного SPI
DATA_DDR & SCK_DDR & LATCH_DDR | Регистр конфигурации порта SPI для сдвигового регистра, при USE_HARDWARE_SPI = 1 указать регистр конфигурации порта хардварного SPI
DATA_PORT & SCK_PORT & LATCH_PORT | Регистр порта SPI для сдвигового регистра, при USE_HARDWARE_SPI = 1 указать регистр порта хардварного SPI
BYTE_ORDER | Порядок отправки данных в сдвиговой регистр обраный/прямой
HC595_COUNT | Кол-во подключеных сдвиговых регистров
 
 
## Configuring 74hc595.h EN

Define | Description
| ------------- | ------------- |
USE_HARDWARE_SPI | If set 1 - Hardware SPI else  if set 0 - Soft SPI
DATA 0 & SCK 3 & LATCH 4 | Shift register connection pins, with USE_HARDWARE_SPI = 1 set the hardware SPI pins
DATA_DDR & SCK_DDR & LATCH_DDR | SPI port configuration register for the shift register with USE_HARDWARE_SPI = 1 must be set  as the hardware SPI port configuration register
DATA_PORT & SCK_PORT & LATCH_PORT | SPI port register for the shift registrar with USE_HARDWARE_SPI = 1 must be set  as  the register of the hardware SPI port
BYTE_ORDER | If set 1 - Left adjusted else right adjusted
HC595_COUNT | Count of connected shift registers
