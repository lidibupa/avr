# Makefile for blink
# Note to change makefile for a new chip change all
# mmcu and dpart statements to reflect new chip

# default target when "make" is run w/o arguments
all: blink.hex

# compile blink.c into blink.o
blink.o: blink.c 
	avr-gcc -c -g -Os -Wall -mmcu=attiny85 blink.c -o blink.o

# link up blink.o into blink.elf
blink.elf: blink.o
	avr-gcc blink.o -Wall,-nm,-Map=blink.map,--cref -mmcu=attiny85 -o blink.elf

# copy hex (FLASH) object out of blink.elf into blink.hex
blink.hex: blink.elf
	avr-objcopy -O ihex blink.elf blink.hex

# command to program chip (optional) (invoked by running "make install")
install:
	avrdude -p t85 -c stk500v2 -P usb -e -U flash:w:blink.hex
	
installPC:
	avrdude -p t85 -c stk500v2  -P COM3 -e -U flash:w:blink.hex
	
# command to clean up junk (no source files) (invoked by "make clean")
clean:
	rm -f *.o *.hex *.elf *.map *.hex *~