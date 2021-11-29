#ifndef BLUETOOTH_H
#define BLUETOOTH_H



void USART_init(void);
void USART_putstring(char *str);
void USART_send(unsigned char data);
unsigned char USART_receive(void);

#endif