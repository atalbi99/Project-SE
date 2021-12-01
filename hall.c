// Fichier test faire clignoter la led bleue sur effet Hall

//#################################     CONFIGURATION    #########################################          

// AVR headers
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdint.h>
#include "hall.h"


void Effet_Hall(void) {

   // Pin is output (low impedance) - LED bleue
   DDRD |= _BV(PD6);
   // Pin is input (bit 2 == 0) - entrée pin effet Hall
   DDRD &= ~_BV(PD2);        

 //#################################     Boucle infinie    #########################################

   while(1){   

      if (!(PIND & 0x04)){
         PORTD |= _BV(PD6);  
      }            
      PORTD &= ~_BV(PD6); 
   }                   
} 


/* #include "bluetooth.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

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
 */