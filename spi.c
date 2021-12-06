#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "spi.h"

void SPI_master_init(void)
{
    /* Set MOSI and SCK output, all others input */
    DDRB = (1<<DDB3)|(1<<DDB5);
    /* Enable SPI, Master, set clock rate fck/16 */
    SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);

    PORTB|=(1<<DDB2);

    DDRC |= (1<<DDC1);
    PORTC |= (1<<PORTC1);

    DDRC |= (1<<DDC2);
    PORTC &= ~(1<<PORTC2);


}


void SPI_master_transmit(char cData)
{
    /* Start transmission */
    SPDR = cData;
    /* Wait for transmission complete */
    while(!(SPSR & (1<<SPIF)));
}

