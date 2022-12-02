#include "config.h"
#include <xc.h>

volatile char previous_PORTB_RB5 = 0;  
volatile char previous_PORTB_RB4 = 0; 
int incremento=0;
void main( void ){

    OSCCONbits.IRCF = 0b111;
    OSCTUNEbits.PLLEN = 0b1; 

    TRISDbits.TRISD3 = 0;
    TRISDbits.TRISD2 = 0;
    
    
    LATDbits.LATD3 = 0;
    LATDbits.LATD2 = 0;

    TRISBbits.TRISB5 = 1;
    TRISBbits.TRISB4 = 1;

    ANSELBbits.ANSB5 = 0;
    ANSELBbits.ANSB4 = 0;

    RCONbits.IPEN = 1;    
    INTCONbits.GIEH = 1; 
    

    IOCBbits.IOCB5 = 1;  
    IOCBbits.IOCB4 = 1;    
    INTCON2bits.RBIP = 1;  
    INTCONbits.RBIF = 0;  
    INTCONbits.RBIE = 1;  
    
    TRISB = 0;
    TRISA=0;
    int counter=0;
    int nums[] = {0b00111111,
                  0b00000110,
                  0b01011011,
                  0b01001111,
                  0b01100110,
                  0b01101101,
                  0b01111101,
                  0b00000111,
                  0b01111111,
                  0b01100111};
    int digits[] = {0b00000111,
                    0b00001011,
                    0b00001101,
                    0b00001110};
    while(1){
        for(int i=0;i<50;i++){
            for(int j=0;j<4;j++){
                PORTB=nums[(counter/pow(10,j))%10];
                PORTA=digits[j];
                __delay_ms(5);
            }

        }
        counter+=counter+incremento;
    
return;}



void __interrupt() ISR_high(){
    

    if(INTCONbits.RBIF == 1 && INTCONbits.RBIE == 1){
        __delay_ms(50);
        char current_PORTB = PORTB;
        if (current_PORTB==13){
          incremento=0;
        }
      if (current_PORTB==14){
        incremento=-1;
        }
      else{ kpi = Keypad_Key_Click(); 
           count=0;
   while (1);
     switch (kpi)
     {
     case 1: count+= 1; break;
     case 2: count+= 2; break; 
     case 3: count+= 3; break; 
     case 4: count+= 4; break; 
     case 5: count+= 5; break; 
     case 6: count+= 6; break;
     case 7: count+= 7; break; 
     case 8: count+= 8; break; 
     case 9: count+= 9; break; 
     case 10: break; 

     }
          count*=10;
          }
        __delay_ms(1000);
        current_PORTB = PORTB;
        previous_PORTB_RB5 = (current_PORTB & 0b00100000) >> 5;
        previous_PORTB_RB4 = (current_PORTB & 0b00010000) >> 4;
        INTCONbits.RBIF = 0;
    }
}

