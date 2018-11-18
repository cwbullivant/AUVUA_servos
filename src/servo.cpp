#include "servo.h"

void initServos() {
  // first servo on pin 5
  TCCR3B |= (1 << CS31);
  TCCR3B &= ~(1 << CS30 | 1 << CS32);
  TCNT3 = 0;

  TIFR3 |= (1 << OCF3A); // clear pending interrupt, if it exists
  TIMSK3 |= (1 << OCIE3A); // enables output compare interrupt

  // second servo on pin 7
  TCCR4B |= (1 << CS41);
  TCCR4B &= ~(1 << CS40 | 1 << CS42);
  TCNT4 = 0;

  TIFR4 |= (1 << OCF4B);
  TIMSK4 |= (1 << OCIE4B);
}
