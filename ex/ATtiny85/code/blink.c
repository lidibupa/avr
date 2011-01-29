/*********************************************
 * Author: Leah Buechley
 * Filename: blink.c
 * Chip: ATtiny85
 */

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include "../leah_library/pin_macros.h"

int main (void)
{
	//setup
	b0Output();
	
	//loop
	for(;;)		//forever
	{	
		b0High();
		_delay_ms(1000);
		b0Low();
		_delay_ms(1000);
	}
	return 0;
}
