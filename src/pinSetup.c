#include "macros.h"
#include "stdint.h"

void pinMode(volatile uint8_t *reg, uint8_t pin, uint8_t state) {
    if (state == OUTPUT) {
        *reg |= (1 << pin);
    } else if (state == INPUT || state == INPUT_PULLUP) {
        *reg &= ~(1 << pin);
        if (state == INPUT_PULLUP && reg == &DDRB) {
            PORTB |= (1 << pin);
        }
    }
}
