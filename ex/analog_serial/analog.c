/* Simple example for Teensy USB Development Board
 * http://www.pjrc.com/teensy/
 * Copyright (c) 2008 PJRC.COM, LLC
 */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdint.h>
#include <util/delay.h>
#include "usb_serial.h"
#include "analog.h"

#define LED_CONFIG	(DDRD |= (1<<6))
#define LED_ON		(PORTD &= ~(1<<6))
#define LED_OFF		(PORTD |= (1<<6))
#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

static uint8_t aref = (1<<REFS0); // default to aref = Vcc

void analogReference(uint8_t mode) 
{
    aref = mode & 0xC0;
}

// Arduino compatible pin input
int16_t analogRead(uint8_t pin)
{
    static const uint8_t PROGMEM pin_to_mux[] = {
        0x00, 0x01, 0x04, 0x06, 0x07,
        0x25, 0x24, 0x23, 0x22, 0x21, 0x20};
    if (pin >= 12) return 0;
    return adc_read(pgm_read_byte(pin_to_mux + pin));
}

int16_t adc_read(uint8_t mux)
{
    uint8_t low;

    ADCSRA = (1<<ADEN) | ADC_PRESCALER;
    ADCSRB = (1<<ADHSM) | (mux & 0x20);
    ADMUX = aref | (mux & 0x1F);
    ADCSRA = (1<<ADEN) | ADC_PRESCALER | (1<<ADSC);
    while (ADCSRA & (1<<ADSC));
    low = ADCL;
    return (ADCH << 8) | low;
}


char charTest = 'x';
int analogR;

// Very simple character echo test
int main(void)
{
	CPU_PRESCALE(0);
	usb_init();
    LED_CONFIG;
    LED_OFF;
	while (1) {
        analogR = analogRead(1);
		int n = usb_serial_getchar();
		if (n >= 0) usb_serial_putchar(n);
        usb_serial_putchar(analogR);
        if (analogR > 0) {
            LED_ON;
        } else {
            LED_OFF;
        }
	}
}

