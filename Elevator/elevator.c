#include <mega164a.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>

void check(int floor)
{
    int sensors;
    int conversion = 0;
    int complete = 0;
    while(complete == 0)
    {
    sensors = PINC;
    switch(sensors)
    {
        case 0b11111110:
            conversion = 1;
        break;
        case 0b11111101:
            conversion = 2;
        break;
        case 0b11111011:
            conversion = 3;
        break;
        default:
        
        break;
    }
    if(conversion == floor)
    {
        complete = 1;
    }
    }
}

void ligth(int floor)
 {
    switch(floor)
    {
        case 1:
              {
              PORTB = (1<<PORTB5) | (0<<PORTB6) | (0<<PORTB7) ;
              }
        break;
        
        case 2:
              {
              PORTB = (0<<PORTB5) | (1<<PORTB6) | (0<<PORTB7) ;
              }
        break;
        
        case 3:
              {
              PORTB = (0<<PORTB5) | (0<<PORTB6) | (1<<PORTB7) ;
              }
        break;
        default: break;
    }
 }

void main(void)
{
 int floor = 1;
 int input;
 DDRB = 0xff;
 DDRD = 0x00;
 DDRC = 0x00;
 PORTC = 0xff; 
 
 TCCR0A = 0x83;
 OCR0A = 0x00;
 OCR0B = 0x00;
 TCCR0B = 0x01;
   

while (1){
        scanf("%d", &input);
        switch(input)
        {
        case 1:
        {
        while (floor!=1)
        {
        if(floor<1)
        {
        PORTB = (1<<PORTB2) | (0<<PORTB1);
        OCR0A = 50;
        check(input);
        floor++;
        }
        else if(floor >1) 
        {
            PORTB = (0<<PORTB2) | (1<<PORTB1);
            OCR0A = 50;
            check(input);
            floor--;
        }    
        }
        ligth(floor);
        OCR0A = 0x00;
        printf("Etajul %d \n", floor);
        }
        break;
         case 2:
        {
        while (floor!=2)
        {
        if(floor<2)
        {      
        PORTB = (1<<PORTB2) | (0<<PORTB1);
        OCR0A = 50;
        check(input);
        floor++;
        }
        else if(floor >2) 
        {       
            PORTB = (0<<PORTB2) | (1<<PORTB1);
            OCR0A = 50;
            check(input);
            floor--;
        }    
        }
        OCR0A = 0x00; 
        ligth(floor);
        printf("Etajul %d \n", floor);
        }
        break;
         case 3:
        {
        while (floor!=3)
        {
        if(floor<3)
        {
        PORTB = (1<<PORTB2) | (0<<PORTB1);
        OCR0A = 50;
        check(input);
        floor++;
        }
        else if(floor >3) 
        {           
            PORTB = (0<<PORTB2) | (1<<PORTB1);
            OCR0A = 50;
            check(input);
            floor--;
        }    
        }
        OCR0A = 0x00;
        ligth(floor);
        printf("Floor %d \n", floor);
        }
        break;
        default:

        break;
        }
        
}
}