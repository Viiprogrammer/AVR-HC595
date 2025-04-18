# 🚀 AVR-HC595 Library
**Library for 74HC595 shift register control on AVR microcontrollers**

## 📌 Quick Start Example
```cpp
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "74hc595.h"

int main(void)
{
    ShiftRegisterInit();
    while(1)
    {
        // Light up LEDs sequentially
        for(int i = 0; i < 2; i++){
            for (int b = 0; b < 8; b++)
            {
                ShiftDigitalWrite(b, HIGH, i);
                strobLatch();
                _delay_ms(300);
            }
        }
        
        // Turn off LEDs sequentially
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
**Note:** Example compiled for ATMEGA8

- 🇷🇺 **Russian**: Пример работы с симуляцией Proteus в [hc595.pdsprj](hc595.pdsprj)
- 🇬🇧 **English**: Proteus simulation example in [hc595.pdsprj](hc595.pdsprj)

## 📚 Function Reference

### 🇷🇺 Описание функций (74hc595.c)

Функция | Описание | Пример | Описание примера |
| ------------- | ------------- | ------------- | ------------- |
`ShiftRegisterInit(void)` | Используется для инициализации сдвиговых регистров | `ShiftRegisterInit();`  | Инициализирует SPI и порты
`ShiftRegisterSend(void)` | Используется для отправки данных на все сдвиговые регистры | `ShiftRegisterSend();` | None
`ShiftDigitalWrite(int pin, int lvl, int number)` | Запись одного пина | `ShiftDigitalWrite(4, HIGH, 2);` | Устанавливает 4ю ногу сдвиггового регистра #3  в HIGH уровень (нумерация сдвиговых регистров от нуля 0)
`ShiftDigitalWritePort(int port, int number)` | Запись данных в весь порт сдвигового регистра | `ShiftDigitalWritePort(0xFF, 1);` | Устанока всех выводов сдвигового регистра #2 (нумерация сдвиговых регистров от нуля 0) в HIGH записью `FF` в порт
`ShiftDigitalGetPort(int number)` | Возврат байта порта| `ShiftDigitalGetPort(1);` | Возвращает актуальную информацию о состоянии порта сдвигового регистра #2 (нумерация сдвиговых регистров от нуля 0)
`strobLatch()` | Выводит данные на выход регистров | `strobLatch();` | -

### 🇬🇧 Functions Description (`74hc595.c`)

| Function                    | Description                                                             | Example                        | Explanation                                                              |
|-----------------------------|------------------------------------------------------------------------|--------------------------------|--------------------------------------------------------------------------|
| `ShiftRegisterInit()`       | Initializes shift registers                                            | `ShiftRegisterInit();`         | Configures SPI and I/O ports                                             |
| `ShiftRegisterSend()`       | Sends data to all shift registers                                      | `ShiftRegisterSend();`         | -                                                                       |
| `ShiftDigitalWrite()`       | Controls single pin                                                    | `ShiftDigitalWrite(4, HIGH, 2);`| Sets pin 4 of third register (0-based) to HIGH                          |
| `ShiftDigitalWritePort()`   | Writes data to entire register port                                    | `ShiftDigitalWritePort(0xFF, 1);`| Sets all pins of second register to HIGH (0xFF)                          |
| `ShiftDigitalGetPort()`     | Reads current port state                                               | `ShiftDigitalGetPort(1);`      | Returns byte from second register                                        |
| `strobLatch()`              | Latches data to register outputs                                       | `strobLatch();`                | -                                                                       |

---


## ⚙️ Configuration (`74hc595.h`)

### 🇷🇺 Настройки

| Параметр            | Описание                                                                 |
|---------------------|--------------------------------------------------------------------------|
| `USE_HARDWARE_SPI`  | `1` - аппаратный SPI, `0` - программный SPI                              |
| `DATA`, `SCK`, `LATCH` | Пины подключения (при USE_HARDWARE_SPI=1 указывать пины аппаратного SPI) |
| `*_DDR`, `*_PORT`   | Регистры управления портами                                              |
| `BYTE_ORDER`        | Порядок отправки данных (`0` - прямой, `1` - обратный)                   |
| `HC595_COUNT`       | Количество подключенных регистров                                        |

### 🇬🇧 Settings

| Parameter           | Description                                                              |
|---------------------|--------------------------------------------------------------------------|
| `USE_HARDWARE_SPI`  | `1` - hardware SPI, `0` - software SPI                                  |
| `DATA`, `SCK`, `LATCH` | Connection pins (for hardware SPI use MCU SPI pins)                    |
| `*_DDR`, `*_PORT`   | Port control registers                                                  |
| `BYTE_ORDER`        | Data order (`0` - MSB first, `1` - LSB first)                          |
| `HC595_COUNT`       | Number of connected shift registers                                    |

---

## 📜 License
MIT License - Free to use and modify
