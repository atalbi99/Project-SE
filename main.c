#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>
#include "led.h"
#include "bluetooth.h"
#include "spi.h"
#include "hall.h"


int counter_seconds;
int counter_time;
int hall_detect;

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


ISR(TIMER0_COMPA_vect){
    // detecter un tour
    counter_seconds++;
    char string2[64];

    itoa(counter_seconds, string2, 10); 
    sprintf(string2+strlen(string2),"\n");





    //USART_putstring(string2);

}

ISR(TIMER1_COMPA_vect){

    counter_time++;
    
}



void init_interrupt(){

    // Make it to input
    DDRD &= ~(1<<DDD0); 
    PORTD |= (1<<PORTD0);
    // Enable interruption of detector on rising edge 
    EICRA |= (1<<ISC01)|(1<<ISC00);
    // Activate INT0
    EIMSK |= (1<<INT0);
    // Set global interrupt enable

    sei();
    //SREG |= (1<<I); //Met le bit à 1 du global interrupt du status register, permet d'activer les interruptions

}


void init_seconds(void){
  TIMSK0 |=(1<<OCIE0A);
  TCCR0B |= (1<<CS01)|(1<<CS00);
  OCR0A = 250;

}

void init_counter_time(void){
  TIMSK1 |=(1<<OCIE1A);

  TCCR1A |= (1<<WGM11)|(1<<WGM10);
  TCCR1B |= (1<<WGM12)|(1<<WGM13)|(1<<CS10);


  OCR1AH=0;
  OCR1AL=250;

}




int main(void)
{
  int se, mi, ho = 0;
    
counter_seconds = 0;
counter_time = 0;
uint16_t hours_analog = 0;
uint16_t time_seconds = 0;
uint16_t time_minutes = 0;
uint16_t time_hours = 0;
uint16_t step=0;
uint16_t seconds = 0;
uint16_t minutes = 50;
uint16_t hours = 15;


// régler le temps
if(seconds >= 60){
  seconds -= 60;
}
if(minutes >= 60){
  minutes -= 60;
}
if (hours >= 24){
  hours -= 24;
}
if(hours >= 12){
  hours_analog = hours - 12;
}
else{
  hours_analog = hours;
}


  USART_init();
SPI_master_init();
init_interrupt();
init_seconds();
init_counter_time();

while(1){


   //USART_putstring( "Enter time \n" );
  // _delay_ms(1);

if ( USART_buffer[0] != '\0' ){

  if(USART_buffer[0] == 'h'){     
    int i = 1;
    for(i=1;i<7;i++){                
      if(USART_buffer[i] == '\0'){
        bl_reset_buffer();           
    
      }
    }

    char h1 = USART_buffer[1];
    char h2 = USART_buffer[2];
    int ho = 10*((int)h1 - 48)+((int)h2 - 48);
    char m1 = USART_buffer[3];
    char m2 = USART_buffer[4];
    int mi = 10*((int)m1 - 48)+((int)m2- 48);
    char s1 = USART_buffer[5];
    char s2 = USART_buffer[6];    
    int se = 10*((int)s1 - 48)+((int)s2 - 48);

    USART_putstring( "time changed\n" );

    if(se >= 60){
  se -= 60;
}
if(mi >= 60){
  mi -= 60;
}
if (ho>= 24){
  ho -= 24;
}
if(ho >= 12){
  hours_analog = ho - 12;
}
else{
  hours_analog = ho;
}
     uint16_t seconds = se;
uint16_t minutes = mi;
uint16_t hours = ho;
  }

  bl_reset_buffer(); 
 
}



 if( hall_detect >= 1)
  {
      step = counter_time / 60;
      counter_time = 0;
      hall_detect = 0;
  }
// mise à jour du temps
if (seconds * 1625 == counter_seconds)
    {
      seconds++;
      if (seconds >= 60)
      {
        counter_seconds = 0;
        seconds = 0;
        minutes++;
        if (minutes >= 60)
        {
          minutes = 0;
          hours++;
          if (hours >= 24)
          {
            hours = 0;
          }
          else if (hours >= 12)
          {
            hours_analog = hours - 12;
          }
          else
          {
            hours_analog = hours;
          }
        }
      }
    }
 
      if (seconds >= 30){
        time_seconds = seconds - 30;
      }
      else{
        time_seconds = seconds + 30;
      }
      if (minutes >= 30){
        time_minutes = minutes - 30;
      }
      else{
        time_minutes = minutes + 30;
      }
      if (hours_analog >= 6){
        time_hours = hours_analog - 6;
      }
      else{
        time_hours = hours_analog + 6;
      }

      uint16_t s = time_seconds * step;
      
      if (s <= counter_time && s + 8 >= counter_time)
        {
          leds_control(7, 0);
        }
        else
        {
      uint16_t m = time_minutes * step;

      if (m <= counter_time && m + 8 >= counter_time)
        {
          leds_control(0, 255);
        }
        else
        {
          // step = 12
          uint16_t h = (time_hours * step * 5);
          if (h <= counter_time && h + 8 >= counter_time)
          {
            leds_control(0, 7);
          }
          else
          {
            leds_control(0, 0);
          }
        }
        }
}
}
