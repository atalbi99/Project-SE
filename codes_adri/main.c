#include "spi.h"
#include "hall.h"
//#include "clock_num.h"
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
        //Allume_Led(letter[y], 0b00000000);
        Allume_Led(0b00000000, letter[y]);
        //Allume_Led(0b00000000, 0b00000000);
        _delay_ms(0.5);
    }
    // printing the space between the letters
    //SPI_MasterTransmit(0);
    Allume_Led(0b00000000 , 0b00000000);
    _delay_ms(1);
} 


/* void printMessage(char* message[])
{
    int i =0;
    // à remplacer et se baser sur le timer ou effet Hall
    if (!(PIND & 0x04))
    {
        while (message[i] =! '/0')
        {
            printLetter (message[i]);
            i++;
        } 
    }    
}
 */

int main(){
    // Init
    // USART_init();

    SPI_MasterInit();
    // Pin is output (low impedance) - LED bleue
    DDRD |= _BV(PD6);
    // Pin is input (bit 2 == 0) - entrée pin effet Hall
    DDRD &= ~_BV(PD2);        

    char NUMBER9_INV[]= {0b11110001, 0b10010001, 0b10010001, 0b10010001, 0b11111111};
    char NUMBER9[]= {0b11111111, 0b10010001, 0b10010001, 0b10010001, 0b11110001};
    char NUMBER8[]= {0b01101110, 0b10010001, 0b10010001, 0b10010001, 0b01101110};

    char NUMBER7_INV[]= {0b10000000, 0b10001000, 0b10001000, 0b10011111, 0b11101000};
    char NUMBER7[]= {0b11101000, 0b10011111, 0b10001000, 0b10001000, 0b10000000};
    char NUMBER6_INV[]= {0b11111111, 0b10001001, 0b10001001, 0b10001001, 0b10001111};
    char NUMBER6[]= {0b10001111, 0b10001001, 0b10001001, 0b10001001, 0b11111111};
    char NUMBER5_INV[]= {0b11111001, 0b10001001, 0b10001001, 0b10001001, 0b10001111};
    char NUMBER5[]= {0b10001111, 0b10001001, 0b10001001, 0b10001001, 0b11111001};

    char NUMBER2_INV[]= {0b10000011, 0b10000101, 0b10001001, 0b10010001, 0b01100001};
    char NUMBER2[]= {0b01100001, 0b10010001, 0b10001001, 0b10000101, 0b10000011};
    char NUMBER1_INV[]= {0b00100000, 0b01000000, 0b11111111, 0b00000000, 0b00000000};
    char NUMBER1[]= {0b00000000, 0b00000000, 0b11111111, 0b01000000, 0b00100000};
    char NUMBER0[]= {0b11111111, 0b10000001, 0b10000001, 0b10000001, 0b11111111};

    char _[] = {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000};
    char A[] = {0b11111111, 0b10010000, 0b10010000, 0b10010000, 0b11111111};
    char B[] = {0b01101110, 0b10010001, 0b10010001, 0b10010001, 0b11111111};
    char C[] = {0b10000001, 0b10000001, 0b10000001, 0b01000010, 0b00111100};

    char E_INV[] = {0b11111111, 0b10010001, 0b10010001, 0b10010001, 0b10010001};
    char E[] = {0b10010001, 0b10010001, 0b10010001, 0b10010001, 0b11111111};
    char H_INV[] = {0b11111111, 0b00001000, 0b00001000, 0b00001000, 0b11111111};
    char H[] = {0b11111111, 0b00001000, 0b00001000, 0b00001000, 0b11111111};
    char L_INV[] = {0b11111111, 0b00000001, 0b00000001, 0b00000001, 0b00000001};
    char L[] = {0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b11111111};
    char O[] = {0b01111110, 0b10000001, 0b10000001, 0b10000001, 0b01111110};

    // Body
    while(1){

/*          PORTD |= _BV(PD6); // LED ON
        _delay_ms(2000);

        char data1 =  0b00000000;
        char data2 =  0b11111111; 
        Allume_Led(data1, data2);
        _delay_ms(4000);
        Eteint_Led();
        _delay_ms(2000);
        PORTD &= ~_BV(PD6); // Blue LED OFF
        _delay_ms(2000);  */

        // Pin is input (bit 2 == 0) - entrée pin effet Hall
        DDRD &= ~_BV(PD2);     

        if (!(PIND & 0x04))
        {
            printLetter (O);
            printLetter (L);
            printLetter (L);
            printLetter (E);
            printLetter (H);
            printLetter (_);
            printLetter (NUMBER9);
            printLetter (NUMBER9_INV);
            printLetter (NUMBER5);
            printLetter (NUMBER2);
            printLetter (NUMBER1);
            printLetter (NUMBER0);
        }

/*         char* message[]= {NUMBER9,NUMBER8,_,A,B,C '/0'}; 
        printMessage(message);  */
    }
}

