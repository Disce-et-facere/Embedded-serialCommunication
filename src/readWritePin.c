#include "stdint.h"

uint8_t digitalRead(uint8_t pinReg, uint8_t pin){
    return (pinReg & (1 << pin)) ? 1 : 0;
}

void togglePinBit(volatile uint8_t *portReg, uint8_t pin){
    *portReg ^= (1 << pin);
}

void setPinBit(volatile uint8_t *portReg, uint8_t pin){
    *portReg |= (1 << pin);
}

void clearPinBit(volatile uint8_t *portReg, uint8_t pin){
    *portReg &= ~(1 << pin);
}