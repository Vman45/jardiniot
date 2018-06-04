// https://github.com/esp8266/Arduino/blob/master/cores/esp8266/Arduino.h

#ifndef ARDUINO_H
#define ARDUINO_H

#include <iostream>
#include <sstream>
#include <inttypes.h>
#include <math.h> // Est importé par le Arduino.h original
#include <stdlib.h>
#include <chrono>
#include "include/arduinoEmulator/String.h"

typedef uint8_t byte;
typedef bool bolean;

enum PinMode {INPUT, OUTPUT, INPUT_PULLUP};
enum PinVoltage {HIGH, LOW};

void analogWrite(uint8_t pin, short value);
void pinMode(uint8_t pin, PinMode mode);
void digitalWrite(uint8_t pin, uint8_t value);
void delay(int ms);
unsigned long millis(void);

// http://svn.savannah.gnu.org/viewvc/avr-libc/trunk/avr-libc/libc/stdlib/dtostrf.c?revision=1944&view=markup
char* dtostrf (double val, signed char width, unsigned char prec, char *sout);

//https://github.com/esp8266/Arduino/blob/master/cores/esp8266/WString.h
std::string F(std::string str);

class Arduino {
public:
    Arduino() {this->initialTime = std::chrono::steady_clock::now();}
    std::chrono::time_point<std::chrono::steady_clock> initialTime;
};

#endif
