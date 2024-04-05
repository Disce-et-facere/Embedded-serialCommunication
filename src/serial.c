#include "macros.h"
#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "readWritePin.h"

void serialInit() {
    UART_BAUD_REG_HIGH = (unsigned char)((UBRR_VALUE) >> 8);
    UART_BAUD_REG_LOW = (unsigned char)UBRR_VALUE;
    UART_CONTROL_REG_B = (1 << RXEN0) | (1 << TXEN0);
    UART_CONTROL_REG_C = (3 << UCSZ00);
}

uint8_t serialAvaliable(){
    return UART_CONTROL_REG_A & (1 << RXC0);
}

void serialWrite(uint8_t data) {
    // Wait for empty transmit buffer
    while (!(UART_CONTROL_REG_A & (1 << UDRE0)));
    UART_DATA_REG = data;
}

uint8_t serialRead() {
    // Wait for data to be received
    while (!(UART_CONTROL_REG_A & (1 << RXC0)));
    return UART_DATA_REG;
}

void serialWriteString(const char* str) {
    while (*str != '\0') {
        serialWrite(*str);
        str++;
    }
}

char* serialReadString() {
    uint8_t index = 0;
    char receivedChar;
    uint8_t bufferSize = 1;
    char* buffer = (char*)malloc(bufferSize * sizeof(char));
    if (buffer == NULL) {
        return NULL;
    }
    do {
        while (!(UART_CONTROL_REG_A & (1 << RXC0)));
        receivedChar = serialRead();
        buffer[index] = receivedChar;
        index++;
        bufferSize++;
        buffer = (char*)realloc(buffer, bufferSize * sizeof(char));
        if (buffer == NULL) {
            free(buffer);
            return NULL;
        }
    } while (receivedChar != '\n');
    return buffer;
}

void serialParser(){
    //commands
    char ledpower[11] = "ledpower \n\0";
    char invalid[16] = "Invalid Input!\n\0";
    char* buffPointer = serialReadString();
    char buff[14];
    strncpy(buff, buffPointer, 12);
    buff[12] = '\n';
    buff[13] = '\0';

    if(strncmp(buff, ledpower, 9) == 0){
        int value;
        if(sscanf(buffPointer, "%*s %d", &value) == 1) {
            serialWriteString(buff);
            if(value > 127 && value < 256){
                setPinBit(&PORTB, PB0);
            }else if(value <= 127 && value > 0){
                clearPinBit(&PORTB, PB0);
            }else{
                char badValue[44] = "Power value is either too high or too low!\n\0";
                serialWriteString(badValue);
            }
        }
    }else{
        serialWriteString(invalid);
    }
    free(buffPointer);
}