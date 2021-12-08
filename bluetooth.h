#ifndef BLUETOOTH_H
#define BLUETOOTH_H

extern char USART_buffer[100];
extern int current_index_buff;

void USART_init(void);
void USART_putstring(char *str);
void USART_send_char(unsigned char data);
unsigned char USART_receive(void);
void bl_reset_buffer();

#endif