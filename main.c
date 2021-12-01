#include "bluetooth.h"
#include "spi.h"
#include "hall.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <avr/io.h>
#include <stdint.h>


int main(){
    // Init
    USART_init();
    SPI_MasterInit();
    DDRD |= _BV(PD6); // Blue LED as an OUTPUT 
    
    // Body
    while(1){

        PORTD |= _BV(PD6); // LED ON
        _delay_ms(2000);

        char data1 =  0b11110000;
        char data2 =  0b01010101; 
        Allume_Led(data1, data2);
        _delay_ms(4000);
        Eteint_Led();
        _delay_ms(2000);
        PORTD &= ~_BV(PD6); // Blue LED OFF
        _delay_ms(2000);

        unsigned char receivedC;
        if(receivedC = USART_receive()){

            //USART_send('A');
            
        }
    }
}


