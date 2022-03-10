#include <mega32.h>
#include <delay.h>
char num1=0,num2=0,num3=0,num4=0;int i=0;
flash char s7seg[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void hex_to_seg (int k)
{
num4= s7seg[0];         // Â“«—ê«‰
num3= s7seg[k%10];     // Ìò«‰
num2= s7seg[k/10%10]; // œÂê«‰
num1= s7seg[k/10/10];// ’œê«‰ 
}
interrupt[EXT_INT0] void add (void)
{
if (PIND.2==0 && i<999)i++;
}
interrupt[EXT_INT1] void mines (void)
{
if (PIND.3==0 && i>0) i--;
}
void main(void)
{

PORTC=0XFF;
DDRC=0XFF;
PORTD=0X0F;
DDRD=0X0F;
PORTA=0XFF;
DDRA=0XFF;
MCUCR=0X0A;
GICR=0XC0;
GIFR=0XC0;
#asm("sei")


while (1)
    {    
    hex_to_seg(i);
    PORTC=0b00001110;
    PORTA=num1;
    delay_ms(5);
    PORTC=0b00001101;
    PORTA=num2;
    delay_ms(5);
    PORTC=0b00001011;
    PORTA=num3;
    delay_ms(5);
    PORTC=0b00000111;
    PORTA=num4;
    delay_ms(5);
    }
}
