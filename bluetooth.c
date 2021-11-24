#include "bluetooth.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#define FOSC 13000000
#define BAUD 38400
#define CALCUBBR (FOSC/(16*BAUD))-1


unsigned char receivedValue = 'i';
int usartFlag = 0;


void USART_init(void){
    UBRR0H = (CALCUBBR >> 8);
    UBRR0L = CALCUBBR;
    UCSR0A &= ~_BV(U2X0);//disable arduino's auto-double async mode
    UCSR0B |= _BV(RXCIE0);//enable reciever interrupt
    UCSR0B |= _BV(RXEN0) | _BV(TXEN0);//enable RX and TX
    UCSR0C |= _BV(UCSZ01) | _BV(UCSZ00);//set frame: 8data, 1stop
    sei();//global interrupt enable flaag set
    usartFlag = 0;
    receivedValue = 0;
}


void USART_putstring(char *str){
    while(*str != 0x00){
        USART_send(*str);
        str++;
    }
}

unsigned char USART_receive(void){
    while(!(UCSR0A & _BV(UDRE0)));
    return UDR0;
}

void USART_send(unsigned char data){
    while(!(UCSR0A & _BV(UDRE0)));
    UDR0 = data;
}

ISR(USART_RX_vect){
    usartFlag = 1;
    receivedValue = USART_receive();
        if(receivedValue == 'A'){
            USART_putstring("coucou");
} 
}