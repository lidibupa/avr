AVR C Bit Manipulation Tutorial:

| = OR
& = AND
~ = NOT
^ = XOR
<< = SHIFT LEFT
>> = SHIFT RIGHT

0 OR 0 = 0 
0 OR 1 = 1 
1 OR 0 = 1 
1 OR 1 = 1

0 AND 0 = 0 
0 AND 1 = 0 
1 AND 0 = 0 
1 AND 1 = 1

0 XOR 0 = 0 
0 XOR 1 = 1 
1 XOR 0 = 1 
1 XOR 1 = 0

0 NOT = 1 
1 NOT = 0

x |= 0x01; // set bit 0

Anything OR 0 is itself and anything OR 1 is 1

x &= 0x01; // clear bit 0

Anything AND 1 is itself and anything AND 0 is 0

x ^= 0x01; // flip bit 0

Anything XOR 0 is itself and anything XOR 1 changes to its opposite (flips)

if (x & 0x01) // Nonzero if the bit indicated by 0x01 is set
{
}

(0x01 << 2) = 00000100

(0x01 << 7) = 10000000

// Macros

#define b_get(p,m)      ((p) & (m))
#define b_set(p,m)      ((p) |= (m))
#define b_clear(p,m)    ((p) &= ~(m))
#define b_flip(p,m)     ((p) ^= (m))
#define b_write(c,p,m)  (c ? b_set(p,m) : b_clear(p,m))
#define bit(n)          (0x01 << (n))
#define longbit(n)      ((unsigned long)0x00000001 << (n))

b_set(x, 0x01)       // set a bit
b_set(x, bit(5))     // set bit 5
b_clear(x, bit(6))   // clear bit 6 with bitmask
b_flip(x, bit(0)     // flip bit 0

if(b_get(x, bit(3))) // check bit 3
{
}

if(b_get(x, bit(4)))   // Set or clear a bit based on bit 4
{
    b_set(y, bit(0))
} else {
    b_clear(y, bit(0))
}

b_write(b_get(x, bit(4)), y, bit(0)); // same as above as a macro

// If you are using an unsigned long (32 bit) variable x, and have to change a bit, use the macro LONGBIT which creates un unsigned long mask. Otherwise, using the BIT() macro, the compiler will truncate the value to 16-bits.

// Another set of macros from AVR035: Efficient C Coding for AVR

#define SETBIT(ADDRESS,BIT) (ADDRESS |= (1<<BIT)) 
#define CLEARBIT(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT)) 
#define FLIPBIT(ADDRESS,BIT) (ADDRESS ^= (1<<BIT)) 
#define CHECKBIT(ADDRESS,BIT) (ADDRESS & (1<<BIT)) 

#define SETBITMASK(x,y) (x |= (y)) 
#define CLEARBITMASK(x,y) (x &= (~y)) 
#define FLIPBITMASK(x,y) (x ^= (y)) 
#define CHECKBITMASK(x,y) (x & (y)) 

#define VARFROMCOMB(x, y) x 
#define BITFROMCOMB(x, y) y 

#define C_SETBIT(comb) SETBIT(VARFROMCOMB(comb), BITFROMCOMB(comb)) 
#define C_CLEARBIT(comb) CLEARBIT(VARFROMCOMB(comb), BITFROMCOMB(comb)) 
#define C_FLIPBIT(comb) FLIPBIT(VARFROMCOMB(comb), BITFROMCOMB(comb)) 
#define C_CHECKBIT(comb) CHECKBIT(VARFROMCOMB(comb), BITFROMCOMB(comb)) 

Additional Resources:

Efficient C Coding for AVR: http://www.atmel.com/dyn/resources/prod_documents/doc1497.pdf
AVR Freaks :: [C] Bit Manipulation (AKA "Programming 101"): http://www.avrfreaks.net/index.php?name=PNphpBB2&file=printview&t=37871&start=0
GCC Documentation: http://gcc.gnu.org/onlinedocs/
