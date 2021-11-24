#include "bluetooth.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>


int main(){
    USART_init();
     while(1){
        unsigned char receivedC;
        if(receivedC = USART_receive()){

            //USART_send('A');
            

}
     }
}


