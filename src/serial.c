#include "macros.h"
#include "stdint.h"

void serialInit() {
    UART_BAUD_REG_HIGH = (unsigned char)((UBRR_VALUE) >> 8);
    UART_BAUD_REG_LOW = (unsigned char)UBRR_VALUE;
    UART_CONTROL_REG_B = (1 << RXEN0) | (1 << TXEN0);
    UART_CONTROL_REG_C = (3 << UCSZ00);
}

void serialWrite(unsigned char data) {
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
    // Loop through the string until the null terminator is reached
    while (*str != '\0') {
        // Send each character
        serialWrite(*str);
        // Move to the next character in the string
        str++;
    }
}

void serialReadString(char* buffer, uint8_t maxLength) {
    uint8_t index = 0;
    char receivedChar;

    // Read characters until maxLength is reached or until a null terminator is received
    do {
        // Wait for data to be available
        while (!(UART_CONTROL_REG_A & (1 << RXC0)));
        // Read the received character
        receivedChar = serialRead();

        // Store the received character in the buffer
        buffer[index] = receivedChar;
        index++;
    } while (receivedChar != '\0' && index < maxLength);

    // Ensure the buffer is null-terminated
    if (index < maxLength) {
        buffer[index] = '\0';
    }
}