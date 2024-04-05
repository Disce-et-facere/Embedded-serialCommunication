#include <macros.h>
#include "pinFunctions.h"
#include "serial.h"

int main(void){ 
    pinInit();
    serialInit();
    char message[23] = "Enter: ledpower 0-255\n\0";
    serialWriteString(message);
    while (1) {
        if (!digitalRead(PINB, PB1)) {
            togglePinBit(&PORTB, PB0);
        }

        if (serialAvaliable()) {
            serialParser();
        }
    }
    return 0;
}