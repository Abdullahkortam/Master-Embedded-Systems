/*
 * main.c
 *
 *  Created on: ١٣‏/١٠‏/٢٠٢٢
 *      Author: Abdullah kortam
 */

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

void GPIO_INIT()
{
	// Enable PORTD PIN7,6,5 --> LED 2,1,0
	DDRD |= (1<<7) | (1<<6) | (1<<5) ;
}

void EINT_INIT()
{
	//Enable Global interrupt
	sei();

	//Enable External int0 --> Any Logical Interrupt
	MCUCR |= (1<<0) ;

	//Enable External int1 --> Rising Edge
	MCUCR |= (1<<2) | (1<<3) ;

	//Enable External int2 --> Falling Edge
	MCUCSR &= ~(1<<6) ;

	//Enable E.interrupt
	GICR |= (1<<7) | (1<<6) | (1<<5) ;
}

ISR(INTO_vect)
{
	PORTD |= (1<<5);
	_delay_ms(1000);
}

ISR(INT1_vect)
{
	PORTD |= (1<<6);
	_delay_ms(1000);
}

ISR(INT2_vect)
{
	PORTD |= (1<<7);
	_delay_ms(1000);
}
void main()
{
	GPIO_INIT();
	EINT_INIT();

	while(1)
	{
		PORTD &= ~((1<<7) | (1<<6) | (1<<5)) ;
	}

}
