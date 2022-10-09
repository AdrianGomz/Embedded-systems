// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
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
void main(void) {
    TRISD=0b00000011;
    TRISB = 0;
    int i = 0b00000000;
    while(1)
    {
//        Revisar pausa
       if(RD0==1 && RD1==1){
           i=i;
       }
//       Revisar reset
       else if(RD0==0 && RD1==0){
           i=0;
       }

//       Revisar si es ascendente
       else if (RD1==1){
//         Caso en que se llegue al valor maximo
           if(i==0b11111111){
               i=0;
           }else{
               i++;
           }
//      Revisar si es descendente
       }else if(RD0==1){
//         Caso en el que se llega a 0
           if(i==0){
               i=0b11111111;
           }else{
               i--;
           }
           
       }
//       Setear puerto al valor
       PORTB = i;
       //Delay
       __delay_ms(1000);
          
    }
    return;
}