#include "spi.h"
#include "led.h"
#include "bluetooth.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>


void leds_control(uint8_t data1, uint8_t data2)
{


    PORTC |= (1<<PORTC1);

    SPI_MasterTransmit(data1);
    SPI_MasterTransmit(data2);

    PORTC |= (1<<PORTC2);

    PORTC &= ~(1<<PORTC2);

    PORTC &= ~(1<<PORTC1);
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
