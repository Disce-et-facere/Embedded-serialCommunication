#include "stdint.h"

uint8_t digitalRead(uint8_t readReg, uint8_t pin){
    return (readReg & (1 << pin)) ? 1 : 0;
}

void toggleOutputPinState(volatile uint8_t *port, uint8_t pin){
    *port ^= (1 << pin);
}