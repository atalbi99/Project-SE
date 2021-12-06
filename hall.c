#include "bluetooth.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

int hall_detect = 0;

void init_hall()
{
    // Make it to input
    DDRD &= ~(1<<DDD0); 
    PORTD |= (1<<PORTD0);
    // Enable interruption of detector on rising edge 
    EICRA |= (1<<ISC01)|(1<<ISC00);
    // Activate INT0
    EIMSK |= (1<<INT0);
    // Set global interrupt enable
    sei();  
}

ISR(INT0_vect){
    hall_detect++;
}
