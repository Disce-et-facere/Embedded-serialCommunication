#ifndef SERIAL_H
#define SERIAL_H

void serialInit();
void serialWrite(uint8_t data);
uint8_t serialRead();
void serialWriteString(const char* str);
void serialReadString(char* buffer, uint8_t maxLength);

#endif  // SERIAL_H