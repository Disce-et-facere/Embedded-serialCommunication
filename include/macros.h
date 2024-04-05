#ifndef MACROS_H
#define MACROS_H

#include "stdint.h"
//Port & pins
#define PORTB (*(volatile uint8_t *)0x25) // PORT B REGISTER
#define DDRB  (*(volatile uint8_t *)0x24) // DATA DIRECTION REGISTER B
#define PINB  (*(volatile uint8_t *)0x23) // PIN REGISTER B
#define PB0 0 // pin 8 led
#define PB1 1 // pin 9 button
// general macros
#define OUTPUT 1
#define INPUT 0
#define INPUT_PULLUP 2
#define HIGH 1
#define LOW 0
// Serial Register addresses and Bits.
#define UDR0   (*(volatile uint8_t *)0xC6) // USART DATA REGISTER 0 (Universal Synchronous/Asynchronous Receiver-Transmitter)
#define UBRR0H (*(volatile uint8_t *)0xC5) // USART BAUD REGISTER HIGH
#define UBRR0L (*(volatile uint8_t *)0xC4) // USART BAUD REGISTER LOW
#define UCSR0B (*(volatile uint8_t *)0xC1) // USART CONTROL REGISTER B
#define UCSR0A (*(volatile uint8_t *)0xC0) // USART CONTROL REGISTER A
#define UCSR0C (*(volatile uint8_t *)0xC2) // USART CONTROL REGISTER C
#define SREG_I 7 // STATUS REGISTER BIT I(7)
#define RXCIE0 7 // USART CONTROL REGISTER B BIT 7
#define TXCIE0 6 // USART CONTROL REGISTER B BIT 6 
#define UDRIE0 5 // USART CONTROL REGISTER B BIT 5
#define RXEN0  4 // USART CONTROL REGISTER B BIT 4
#define TXEN0  3 // USART CONTROL REGISTER B BIT 3
#define UCSZ02 2 // USART CONTROL REGISTER B BIT 2
#define RXB80  1 // USART CONTROL REGISTER B BIT 1
#define TXB80  0 // USART CONTROL REGISTER B BIT 0
#define RXC0   7 // USART CONTROL REGISTER A BIT 7
#define UDRE0  5 // USART CONTROL REGISTER A BIT 6
#define UCSZ00 1 // USART CONTROL REGISTER C BIT 1

#endif  // MACROS_H