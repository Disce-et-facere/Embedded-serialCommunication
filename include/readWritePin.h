#ifndef READWRITEPIN_H
#define READWRITEPIN_H

uint8_t digitalRead(uint8_t readReg, uint8_t pin);
void toggleOutputPinState(volatile uint8_t *port, uint8_t pin);

#endif  // READWRITEPIN_H