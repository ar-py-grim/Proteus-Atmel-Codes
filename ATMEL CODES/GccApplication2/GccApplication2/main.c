#define F_CPU 1000000UL
#include <avr/io.h>
void T1();
int main(void)
{
	DDRB=0x02;
    while (1) 
    {
		PORTB=PORTB^(1<<PB1);
		T1();
	}
	return 0;
}
void T1()
{
	TCCR1A=0x00;
	TCCR1B=0x03;
	TCNT1=0xC2F7;
	if((TIFR&(1<<TOV1))==0)
	{
		TCCR1B=0;
		TIFR=(1>>TOV1);
	}
}