#include <macros.h>
#include "stdint.h"

void pinMode(volatile uint8_t *dataDirection, uint8_t pin, uint8_t state) {
    if (state == OUTPUT) {
        *dataDirection |= (1 << pin);
    } else if (state == INPUT || state == INPUT_PULLUP) {
        *dataDirection &= ~(1 << pin);
        if (state == INPUT_PULLUP && dataDirection == &DDRB) {
            PORTB |= (1 << pin);
        }
    }
}

void pinInit(){
    pinMode(&DDRB, PB0, OUTPUT);
    pinMode(&DDRB, PB1, INPUT_PULLUP);
}