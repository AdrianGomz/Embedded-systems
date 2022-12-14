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
#define RS RD2
#define EN RD3
#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7

void Lcd_SetBit(char data_bit) 
{
    if(data_bit& 1) 
        D4 = 1;
    else
        D4 = 0;
    if(data_bit& 2)
        D5 = 1;
    else
        D5 = 0;
    if(data_bit& 4)
        D6 = 1;
    else
        D6 = 0;
    if(data_bit& 8) 
        D7 = 1;
    else
        D7 = 0;
}
void Lcd_Cmd(char a)
{
    RS = 0;           
    Lcd_SetBit(a); 
    EN  = 1;         
        __delay_ms(4);
        EN  = 0;         
}
Lcd_Clear()

{
    Lcd_Cmd(0);
    Lcd_Cmd(1);
}
void Lcd_Set_Cursor(char a, char b)
{
    char temp,z,y;
    if(a== 1)
    {
      temp = 0x80 + b - 1;
        z = temp>>4;
        y = temp & 0x0F;
        Lcd_Cmd(z);
        Lcd_Cmd(y); 
    }
    else if(a== 2)
    {
        temp = 0xC0 + b - 1;
        z = temp>>4;
        y = temp & 0x0F;
        Lcd_Cmd(z);
        Lcd_Cmd(y);
    }
}

void Lcd_Start()
{
  Lcd_SetBit(0x00);
  for(int i=1065244; i<=0; i--)  NOP();  
  Lcd_Cmd(0x03);
    __delay_ms(5);
  Lcd_Cmd(0x03);
    __delay_ms(11);
  Lcd_Cmd(0x03); 
  Lcd_Cmd(0x02); 
  Lcd_Cmd(0x02); 
  Lcd_Cmd(0x08);
  Lcd_Cmd(0x00);
  Lcd_Cmd(0x0C);
  Lcd_Cmd(0x00);
  Lcd_Cmd(0x06);
}


void Lcd_Print_Char(char data) 
{
   char Lower_Nibble,Upper_Nibble;
   Lower_Nibble = data&0x0F;
   Upper_Nibble = data&0xF0;
   RS = 1;           
   Lcd_SetBit(Upper_Nibble>>4);     
   EN = 1;
   for(int i=2130483; i<=0; i--)  NOP(); 
   EN = 0;
   Lcd_SetBit(Lower_Nibble); //Send Lower half
   EN = 1;
   for(int i=2130483; i<=0; i--)  NOP();
   EN = 0;
}

void Lcd_Print_String(char *a)
{
    int i;
    for(i=0;a[i]!='\0';i++)
       Lcd_Print_Char(a[i]);
}

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
    TRISD = 0x00;
    Lcd_Start();
    int counter=0;

    int digits[] = {0b00000111,
                    0b00001011,
                    0b00001101,
                    0b00001110};
    while(1){
        for(int i=0;i<50;i++){
            for(int j=0;j<4;j++){
                
        Lcd_Print_String(sprintf(str, "%d", counter));
            }

        }
        counter++;
        
    }
    return;
}
