#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>



#ifndef BLUETOOTH_H
#define BLUETOOTH_H

void USART_init(void);
void USART_putstring(char *str);
void USART_send(unsigned char data);
unsigned char USART_received(void);

#endif