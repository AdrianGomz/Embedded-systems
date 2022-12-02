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

           INTF = 0;    
            milli_sec=0; 
            distance= distance+2;
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

        d1 = (distance/100)%10;
        d2 = (distance/10)%10;
        d3 = (distance/1)%10;

        if (milli_sec>1000)
        {
            speed=0;
        }
        Lcd_Set_Cursor(1,1);
        Lcd_Print_String("m: ");
        Lcd_Print_Char(d1+'0');
        Lcd_Print_Char(d2+'0');
        Lcd_Print_Char(d3+'0');
    }

    return 0;

}
