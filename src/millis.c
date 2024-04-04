#include "macros.h"

void timerInit(){
    TCCR1B_REG |= (1 << WGM12_BIT);
    TCCR1B_REG |= (1 << CS11_BIT) | (1 << CS10_BIT);
    OCR1A_REGH = (uint8_t)((F_CPU / 64 / TIMER_FREQUENCY - 1) >> 8);
    OCR1A_REGL = (uint8_t)((F_CPU / 64 / TIMER_FREQUENCY - 1) & 0xFF);
    TIMSK1_REG |= (1 << OCIE1A_BIT);
}



void TIMER1_COMPA_ISR(){
    enableGlobalInterupt();

    clearGlobalInterupt();
}
void enableGlobalInterupt(){
    STATUS_REGISTER |= (1 << SREG_I);
}

void clearGlobalInterupt(){
    STATUS_REGISTER &= ~(1 << SREG_I);
}

