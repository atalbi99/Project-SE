// Fichier test faire clignoter la led bleue 

//#################################     CONFIGURATION    #########################################          

// AVR headers
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>


//#define _BV(PD6) (1<<(6))

void main() {


// Pin is output (low impedance)
DDRD |= _BV(PD6);
// Pin is input (bit 2 == 0)
DDRD &= ~_BV(PD2);        

 //#################################     Boucle infinie    #########################################

while(1){   

   // if (PORTD & ))
   if (!(PIND & 0x04)){
      PORTD |= _BV(PD6);  
   }            
   PORTD &= ~_BV(PD6); 

   /*  
     // The pin is "high" level (eg 5V)
    PORTD |= _BV(PD6);      
    _delay_ms(500);
    // The pin is "low" level (eg 0V)              
    PORTD &= ~_BV(PD6);      
    _delay_ms(500);
 */

 }                   
} 