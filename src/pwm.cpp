#include "pwm.h"

void initPWMTimer3A() {
  DDRE |= (1 << DDE3); // set pin 5 as output
  TCCR3A |= (1 << WGM31) | (1 << WGM30); // 10 bit phase correct PWM
}

void initPWMTimer4B() {
  DDRH |= (1 << DDH4); // pin 7 as output
  TCCR4A |= (1 << WGM41) | (1 << WGM40);
}
