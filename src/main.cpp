#include <avr/io.h>
#include <avr/interrupt.h>
#include "pwm.h"
#include "servo.h"
#include "timer.h"

//Use pins 5 and 7 for this demo

typedef enum stateEnum {neutral, forward_deb, forward,
                        reverse_deb, reverse} state;
volatile state currState; // volatile keyword needed for ISR

int main() {
  sei(); // enable global interrupts
  initPWMTimer3A(); // initialize Timer3 channel A for PWM
  initPWMTimer4B(); // initialize Timer4 channel B for pwm

  initServos(); // send initialization signal to servos


  for (;;) {
    switch (currState) {
      case neutral:
        break;
      case forward_deb:
        break;
      case forward:
        break;
      case reverse_deb:
        break;
      case reverse:
        break;
    }
  }
}
