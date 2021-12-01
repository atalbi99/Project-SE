// Fichier test pour la liaion SPI

//#################################     CONFIGURATION    #########################################          

// AVR headers
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdint.h>
#include "spi.h"


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

DDRC |= _BV(PC1); // /OE
DDRC |= _BV(PC2); // LE

Eteint_Led();
}

void SPI_MasterTransmit(char cData)
{
/* Start transmission */

SPDR = cData;
/* Wait for transmission complete */
while(!(SPSR & (1<<SPIF)));
}

void Allume_Led(char data1, char data2){
    PORTC &= ~_BV(PC1); // /OE == 0
    PORTC |= _BV(PC2); // LE == 1
    SPI_MasterTransmit(data1);
    SPI_MasterTransmit(data2);
}

void Eteint_Led(){
    PORTC |= _BV(PC1); // /OE == 1
    PORTC &= ~_BV(PC2); // LE == 0
}
