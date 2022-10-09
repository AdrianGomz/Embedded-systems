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
    TRISA=0;
    TRISC=0b11110000;
    int nums[] = {0b00111111,
                  0b00000110,
                  0b01011011,
                  0b01001111,
                  0b01100110,
                  0b01101101,
                  0b01111101,
                  0b00000111,
                  0b01111111,
                  0b01100111,
                  0b01110111,
                  0b01111100,
                  0b00111001,
                  0b01011110,
                  0b01111001,
                  0b01110001};
    int digits[] = {0b00000111,
                    0b00001011,
                    0b00001101,
                    0b00001110};
    int digit_nums[] = {0,0,0,0};
    while(1){
//        PORTA=digits[0];
        PORTA=0b00001110;
        PORTC=0b00000001;
        if (RC4){ 
            digit_nums[3]=1;
            PORTB=nums[1];
            }
        else if (RC5){
                digit_nums[3]=4;
                PORTB=nums[4];
            }
        else if (RC6){
                digit_nums[3]=7;
                PORTB=nums[7];
            }
        else if (RC7){
                digit_nums[3]=15;
                PORTB=nums[15];
            }
//        __delay_ms(500);
        PORTC=0b00000010;
        if (RC4){ 
            digit_nums[3]=2;
            PORTB=nums[2];
            }
        else if (RC5){
                digit_nums[3]=5;
                PORTB=nums[5];
            }
        else if (RC6){
                digit_nums[3]=8;
                PORTB=nums[8];
            }
        else if (RC7){
                digit_nums[3]=0;
                PORTB=nums[0];
            }
//        __delay_ms(500);
        PORTC=0b00000100;
        if (RC4){ 
            digit_nums[3]=3;
            PORTB=nums[3];
            }
        else if (RC5){
                digit_nums[3]=6;
                PORTB=nums[6];
            }
        else if (RC6){
                digit_nums[3]=9;
                PORTB=nums[9];
            }
        else if (RC7){
                digit_nums[3]=14;
                PORTB=nums[14];
            }
//        __delay_ms(500);
        PORTC=0b00001000;
        if (RC4){ 
            digit_nums[3]=10;
            PORTB=nums[10];
            }
        else if (RC5){
                digit_nums[3]=11;
                PORTB=nums[11];
            }
        else if (RC6){
                digit_nums[3]=12;
                PORTB=nums[12];
            }
        else if (RC7){
                digit_nums[3]=13;
                PORTB=nums[13];
            }
//        __delay_ms(500);
//        for(int i=0;i<50;i++){
//            for(int j=0;j<4;j++){
//                PORTB=nums[digit_nums[j]];
//                PORTA=digits[j];
                
                __delay_ms(5);
//            }
//
//        }
        
        
    }
    return;
}
