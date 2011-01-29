// partial TWI example taken from somewhere... PJRC?

void i2cInit()
{
	cbi(DDRD, 0);
    cbi(DDRD, 1); // input state for now
	cbi(PORTD, 0);
    cbi(PORTD, 1); // disables pull up
	// pull up resistors are external

	TWBR = 1; // fast i2c
	TWSR = 0b00000011; // prescale 64, fast i2c
	TWCR = 0b01000101; // i2c on, interrupt enable, ack enable

	TWAR = 0b00111010; // slave address for accelerometer
	// apparently this is only used for slave mode, but keep it here
}

void i2cStop()
{
	while ((TWCR & _BV(TWINT)) == 0);
	TWCR = _BV(TWINT) | _BV(TWSTO) | _BV(TWEN); // stop
}

void i2cStart()
{
	while((TWCR & _BV(TWINT)) == 0); // wait
	TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN); // start
}

void i2cSLA_R()
{
	TWDR = 0b00111011;
	while ((TWCR & _BV(TWINT)) == 0);
	TWCR = _BV(TWINT) | _BV(TWEN); // clear int to start transmission
}

void i2cSLA_W()
{
	TWDR = 0b00111010;
	while ((TWCR & _BV(TWINT)) == 0);
	TWCR = _BV(TWINT) | _BV(TWEN); // clear int to start transmission
}

void i2cWrite(uint8_t data)
{
	TWDR = data;
	while ((TWCR & _BV(TWINT)) == 0);
	TWCR = _BV(TWINT) | _BV(TWEN); // clear int to start transmission
}

void i2cReadStart()
{
	while ((TWCR & _BV(TWINT)) == 0);
	TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWEA); // clear int to start transmission
}

uint8_t i2cRead()
{
	while ((TWCR & _BV(TWINT)) == 0);
	return TWDR;
} 

