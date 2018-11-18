#ifndef PWM_H
#define PWM_H

#include <avr/io.h>
#include <avr/interrupt.h>

void initPWMTimer3A();
void initPWMTimer4B();

void setFreq(unsigned int pulseWidth);

#endif
