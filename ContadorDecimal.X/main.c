/*
 * File:   main.c
 * Author: Dell Touch
 *
 * Created on September 12, 2022, 8:59 AM
 */


#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XTAL_FREQ 16000000 
int pow(int b, int pow){
    int ans=1;
    for (int i=0;i<pow;i++){
        ans*=b;
    }
    return ans;
}

void main(void) {
    
    TRISB = 0;
//    TRISA=0;
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
        counter++;
        
    }
    return;
}
