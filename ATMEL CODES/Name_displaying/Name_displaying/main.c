# define F_CPU 1000000UL
#include<avr/io.h>
#include<stdint.h>
#include<util/delay.h>
#define LCD_DATA PORTB     //data line
#define ctrl PORTC        //command line
#define en PC2
#define rs PC0
void LCD_cmd(unsigned char cmd);
void init_LCD();
void LCD_print(unsigned char data);

void init_LCD(){
	LCD_cmd(0x38);
	_delay_ms(1);
	LCD_cmd(0x0E);            // Display on, cursor blinking
	_delay_ms(1);
	LCD_cmd(0x01);
	_delay_ms(1);
}
void LCD_cmd(unsigned char cmd){
	LCD_DATA=cmd;
	PORTC&=~(1<<rs);
	PORTC|= (1<<en);
	_delay_ms(1);
	PORTC&= ~(1<<en);
}
void LCD_print(unsigned char data){
	LCD_DATA=data;
	PORTC|= (1<<rs);
	PORTC|= (1<<en);
	_delay_ms(1);
	PORTC&= ~(1<<en);
}
int main(void){
	char ch[]=" ARPIT GANDHI ";
	int c=0;
	DDRB=0xFF;    //data line as output
	DDRC|=(1<<rs)|(1<<en);    //command line as output
		init_LCD();
		_delay_ms(10);
		LCD_cmd(0x0C);
		_delay_ms(10);
		while(ch[c]!='\0'){
			LCD_print(ch[c]);
			_delay_ms(1000);
			LCD_cmd(0x06);
			_delay_ms(1000);
			c++;
		}
}