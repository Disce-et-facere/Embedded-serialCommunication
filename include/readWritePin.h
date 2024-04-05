#ifndef READWRITEPIN_H
#define READWRITEPIN_H

uint8_t digitalRead(uint8_t pinReg, uint8_t pin);
void togglePinBit(volatile uint8_t *portReg, uint8_t pin);
void setPinBit(volatile uint8_t *portReg, uint8_t pin);
void clearPinBit(volatile uint8_t *portReg, uint8_t pin);

#endif  // READWRITEPIN_H