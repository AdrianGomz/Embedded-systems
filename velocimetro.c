#pragma config FOSC = HS      
#pragma config WDTE = OFF    
#pragma config PWRTE = ON    
#pragma config BOREN = ON    
#pragma config LVP = OFF     
#pragma config CPD = OFF
#pragma config WRT = OFF   
#pragma config CP = OFF        

#include <xc.h>

void interrupt speed_isr()

{

        if(TMR0IF==1) 
    {  

        TMR0IF=0;   
         milli_sec++;
    } 
    
        if (INTF==1)
        {
           rpm = (1000/milli_sec) * 60;
           speed =  rpm * 2/60; 
           INTF = 0;    
            milli_sec=0; 

        }

}


int main()
{
    TRISD = 0x00;
    TRISB0 = 1;  
    OPTION_REG = 0b00000101;
    TMR0=100;  
    TMR0IE=1; 
    GIE=1;  
    PEIE=1;       
    INTE = 1;       
    Lcd_Start();
    while(1)

    { 
        c1 = (speed/100)%10;
        c2 = (speed/10)%10;
        c3 = (speed/1)%10;


        if (milli_sec>1000)
        {
            speed=0;
        }
        Lcd_Set_Cursor(1,1);
        Lcd_Print_String("Speed(km/hr): ");
        Lcd_Print_Char(c1+'0');
        Lcd_Print_Char(c2+'0');
        Lcd_Print_Char(c3+'0');

    }

    return 0;

}
