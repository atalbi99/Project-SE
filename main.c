#include "bluetooth.h"
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

int main(){
    USART_init();
    while(1){
 if(usartFlag == 1){
            usartFlag = 0;
            USART_send("anas");
        }
    }

}
