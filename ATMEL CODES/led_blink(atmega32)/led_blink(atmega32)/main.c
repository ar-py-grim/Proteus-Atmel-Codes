#define F_CPU 1000000UL
#include <avr/io.h>
#include <util\delay.h>
int main(void)
{
	DDRB=0xFF;  // setting all pins of port B as output
	int i=0;
	int a=0b00000001;
	while (1)
	{
		// turning on led one at a time
		for(i=0;i<8;i++)
		{
			PORTB=a;
			_delay_ms(1000);
			a=a<<1;
		}
		i=0;
		a=0b00000001;  //to repeat the pattern forever
	}
}
