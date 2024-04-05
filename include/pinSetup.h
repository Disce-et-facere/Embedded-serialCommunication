#ifndef PINSETUP_H
#define PINSETUP_H

void pinMode(volatile uint8_t *dataDirection, uint8_t pin, uint8_t state);
void pinInit();

#endif  // PINSETUP_H