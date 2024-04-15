#include "macros.h"
#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "pinFunctions.h"

#define CPU_SPEED 16000000UL // Cpu clock speed
#define BAUD 9600   // baud rate
#define UBRR_VALUE (CPU_SPEED / (16UL * BAUD)) - 1 // USART BAUD RATE REGISTER VALUE
#define MAX_VALUE 255
#define MID_VALUE 127
#define MIN_VALUE 0
#define BUFFER_SIZE 14 // set to whatever fits your need, in this case 14 is enough.

// Initiates serial communication settings
void serialInit() {
    UBRR0H = (unsigned char)((UBRR_VALUE) >> 8); // baud configuration, sets the UBRR high byte
    UBRR0L = (unsigned char)UBRR_VALUE; // baud configuration, sets the UBRR LOW byte
    UCSR0B = (1 << RXEN0) | (1 << TXEN0); // enables reciever and transmitter
    UCSR0C = (3 << UCSZ00); // sets the char size to 8 byte
}

// checks ifs buffer is containing byte(s)
uint8_t serialAvaliable(){
      return UCSR0A & (1 << RXC0);   
}

// transmit single char
void serialWrite(uint8_t data) {
    while (!(UCSR0A & (1 << UDRE0))); // checks if transmition is avaliable
    UDR0 = data; // moves data to be transmitted to data buffer register
}

// receive single char
uint8_t serialRead() {
    while (!(UCSR0A & (1 << RXC0))); // checks ifs buffer is containing byte(s)
    return UDR0; // returns received data from data buffer register
}

// transmit String
void serialWriteString(const char* str) {
    while (*str != '\0') {
        serialWrite(*str);
        str++;
    }
}

// transmit Line
void serialWriteLine(const char* str){
    while (*str != '\0') {
        serialWrite(*str);
        str++;
    }
    serialWrite('\n');
}

// receive string
void serialReadString(char* destination) {
    uint8_t index = 0;
    char receivedChar;
    char readBuffer[BUFFER_SIZE];
    do{
        receivedChar = serialRead();
        readBuffer[index] = receivedChar;
        index++;
    } while (receivedChar != '\n' && index < BUFFER_SIZE);
    readBuffer[index] = '\0';
    strcpy(destination, readBuffer);
    //clears buffer if input is bigger than the buffer size 
    while(receivedChar != '\n'){
        receivedChar = serialRead();
    }
}

void serialParser() {
    char buffer[BUFFER_SIZE];
    serialReadString(buffer);
    const char* commandStr = "ledpower ";
    if (strncmp(buffer, commandStr, strlen(commandStr)) == 0) {
        int value;
        char trailingChar;
        char number[5];
        if (sscanf(buffer, "%*s %d%c", &value, &trailingChar) == 2) {
            if (trailingChar == '\n' || trailingChar == '\0') {
                sprintf(number, "%d\n", value);
                if(value > MID_VALUE && value <= MAX_VALUE){
                    serialWriteString("Power: ");
                    serialWriteLine(number);
                    setPinBit(&LED_PORT, LED_PIN);
                }else if(value <= MID_VALUE && value >= MIN_VALUE){
                    serialWriteString("Power: ");
                    serialWriteLine(number);
                    clearPinBit(&LED_PORT, LED_PIN);
                } else {
                    serialWriteLine("Power value is either too high or too low!");
                }
            } else {
                serialWriteLine("Invalid input!");
            }
        } else {
            serialWriteLine("Invalid input!");
        }
    } else {
        serialWriteLine("Invalid input!");
    }
}
