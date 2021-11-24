#ifndef BLUETOOTH_H
#define BLUETOOTH_H

extern unsigned char receivedValue;
extern int usartFlag;

void USART_init(void);
void USART_putstring(char *str);
void USART_send(unsigned char data);
unsigned char USART_receive(void);

#endif