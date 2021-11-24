// Fichier test pour la liaion SPI

//#################################     CONFIGURATION    #########################################          

// AVR headers
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>


// SDI == MOSI == PB3
// /OE == PC1
// SCK == PB5
// LE == PC2
// clock function ?

void SPI_MasterInit(void)
{
/* Set MOSI and SCK output, all others input */
DDRB = (1<<DDB3)|(1<<DDB5)|(1<<DDB2);
/* Enable SPI, Master, set clock rate fck/16 */

SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void SPI_MasterTransmit(char cData)
{
/* Start transmission */

SPDR = cData;
/* Wait for transmission complete */
while(!(SPSR & (1<<SPIF)));
}


void main() {
    // Init 
// Init Led for check
DDRD |= _BV(PD6); // Blue LED as an OUTPUT 
// Init SPI
DDRB |= _BV(PB2); // /SS as an OUTPUT
DDRC |= _BV(PC1); // /OE
DDRC |= _BV(PC2); // LE
SPI_MasterInit();

PORTC |= _BV(PC1); // /OE == 1
PORTC &= ~_BV(PC2); // LE == 0

    //Body 

PORTC &= ~_BV(PC1); // /OE == 0
PORTC |= _BV(PC2); // LE == 1

//char c = 'x';
char c = 0x53;
SPI_MasterTransmit(c);

PORTD |= _BV(PD6); // LED ON
_delay_ms(1000);

//PORTB |= _BV(PB3); // MOSI

PORTD &= ~_BV(PD6); // LED OFF
//PORTC |= _BV(PC1); // /OE == 1
PORTC &= ~_BV(PC2); // LE == 0
}