// Fichier test pour l'horloge numérique version 1

/* Idée : La pâle met environ 45-50ms à faire un tour donc si on découpe le cercle en 50 sections, chacune de 1ms
   on peut afficher au moins 10 lettres si on considère qu'un Lettre s'affiche sur une largeur de 5 colonnes et 5ms
*/

//#################################     CONFIGURATION    #########################################          


#include "clock_num.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <avr/io.h>
#include <stdint.h>

void printLetter(char letter[])
{
    int y;
    // printing the first y row of the letter
    for (y=0; y<5; y++)
    {
        // SPI_MasterTransmit(letter[y]);
        Allume_Led(letter[y], 0b00000000);
        //Allume_Led(0b00000000, 0b00000000);
        _delay_ms(1.5);
    }
    // printing the space between the letters
    //SPI_MasterTransmit(0);
    Allume_Led(0b00000000 , 0b00000000);
    _delay_ms(4);
}