#ifndef MACROS_H
#define MACROS_H

#include "stdint.h"

#define PORTB (*(volatile uint8_t *)0x25)
#define DDRB  (*(volatile uint8_t *)0x24)
#define PINB  (*(volatile uint8_t *)0x23)

#define PB0 0 // pin 8 led
#define PB1 1 // pin 9 button

#define OUTPUT 1
#define INPUT 0
#define INPUT_PULLUP 2
#define HIGH 1
#define LOW 0

#define F_CPU 16000000UL
#define BAUD 9600
#define UBRR_VALUE (F_CPU / (16UL * BAUD)) - 1
#define UART_DATA_REG      (*(volatile uint8_t *)0xC6)
#define UART_BAUD_REG_HIGH (*(volatile uint8_t *)0xC5)
#define UART_BAUD_REG_LOW  (*(volatile uint8_t *)0xC4)
#define UART_CONTROL_REG_B (*(volatile uint8_t *)0xC1)
#define UART_CONTROL_REG_A (*(volatile uint8_t *)0xC0)
#define UART_CONTROL_REG_C (*(volatile uint8_t *)0xC2)
#define RXCIE0 7
#define TXCIE0 6
#define UDRIE0 5
#define RXEN0  4
#define TXEN0  3
#define UCSZ02 2
#define RXB80  1
#define TXB80  0
#define RXC0   7
#define UDRE0  5
#define UCSZ00 1

#endif  // MACROS_H