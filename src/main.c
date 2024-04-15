#include <macros.h>
#include "pinFunctions.h"
#include "serial.h"

int main(void){ 
    pinInit();
    serialInit();
    serialWriteLine("Enter: ledpower 0-255");
    while (1) {
        if (!digitalRead(BUTTON_PIN_REGISTER, BUTTON_PIN)) {
            togglePinBit(&LED_PORT, LED_PIN);
        }
        
        if (serialAvaliable()) {
            serialParser();
        }
    }
    return 0;
}
