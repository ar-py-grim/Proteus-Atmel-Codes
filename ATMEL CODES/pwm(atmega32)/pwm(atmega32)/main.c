#define F_CPU 16000000UL
#include <avr/io.h>
#include<util\delay.h>
int main(void)
{
	DDRB|=(1<<PB3);
	TCCR0|=(1<<COM01)|(1<<WGM01)|(1<<WGM00);  //non-inverting fast PWM
	TCCR0|=(1<<CS01)|(1<<CS00);   //prescaler=64
	// f(ocn0 fast-pwm) = 1MHz/(256*64) = 488Hz
	unsigned int duty=0;
	while (1)
	{
		for(duty=0;duty<=255;)
		{
			OCR0=duty;
			duty+=10;
			_delay_ms(100);
		}
		
		for(duty=255;duty>=0;)
		{
			OCR0=duty;
			duty-=10;
			_delay_ms(100);
		}
		_delay_ms(2000);
	}
}

