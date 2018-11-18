#include "timer.h"

void initTimer0() {
  TCCR0A |= (1 << WGM01);
}

void delayUs(unsigned int delay) {
  TCCR0B &= ~(1 << CS02 | 1 << CS01 | 1 << CS00);
  OCR0A = 2;

  TCCR0B |= (1 << CS01);

  for (unsigned int i = 0; i < delay; i++) {
    TIFR0 |= (1 << OCF0A);
    TCNT0 = 0;
    while (!(TIFR0 & (1 << OCF0A)));
  }

  TIFR0 |= (1 << OCF0A);

  TCCR0B &= ~(1 << CS02 | 1 << CS01 | 1 << CS00);
}

void delayMs(unsigned int delay) {
  OCR0A = 250;

  TCCR0B |= (1 << CS01) | (1 << CS00);

  for (unsigned int i = 0; i < delay; i++) {
    TIFR0 |= (1 << OCF0A);
    TCNT0 = 0;
    while (!(TIFR0 & (1 << OCF0A)));
  }


  TCCR0B &= ~(1 << CS02 | 1 << CS01 | 1 << CS00);
}
