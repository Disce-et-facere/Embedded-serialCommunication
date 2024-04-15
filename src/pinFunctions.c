#include <macros.h>
#include "stdint.h"

void pinMode(volatile uint8_t *dataDirection, uint8_t pin, uint8_t state) {
    if (state == OUTPUT) {
        *dataDirection |= (1 << pin); // setting bit (OR) on data direction register
    } else if (state == INPUT || state == INPUT_PULLUP) {
        *dataDirection &= ~(1 << pin); // clearing bit (NOT) on data direction register
        if (state == INPUT_PULLUP && dataDirection == &DDRB) {
            PORTB |= (1 << pin); // setting bit (OR) on port register
        }
    }
}

void pinInit(){
    pinMode(&DDRB, LED_PIN, OUTPUT);
    pinMode(&DDRB, BUTTON_PIN, INPUT_PULLUP);
}

uint8_t digitalRead(uint8_t pinReg, uint8_t pin){
    return (pinReg & (1 << pin)) ? 1 : 0; // checks (AND) if bit on pin register is set to either 1 or 0
}

void togglePinBit(volatile uint8_t *portReg, uint8_t pin){
    *portReg ^= (1 << pin); // toggle bit (XOR) on port register
}

void setPinBit(volatile uint8_t *portReg, uint8_t pin){
    *portReg |= (1 << pin); // set bit (OR) 
}

void clearPinBit(volatile uint8_t *portReg, uint8_t pin){
    *portReg &= ~(1 << pin); // clear bit (NOT) on port register
}
