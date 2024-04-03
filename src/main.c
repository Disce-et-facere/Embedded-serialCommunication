#include "macros.h"
#include "readWritePin.h"
#include "pinSetup.h"
#include "serial.h"

int main(void) {
    pinMode(&DDRB, PB0, OUTPUT);
    pinMode(&DDRB, PB1, INPUT_PULLUP);
    serialInit();
    serialWrite('B');
    while (1) {
        if (digitalRead(PINB, PB1) == LOW) {
            toggleOutputPinState(&PORTB, PB0);
        }

        if (UART_CONTROL_REG_A & (1 << RXC0)) {
            uint8_t receivedData = serialRead();
            serialWrite(receivedData);
        }
    }
    return 0;
}