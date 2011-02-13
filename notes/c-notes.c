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

foo |= 0x01; // set bit 0

Anything OR 0 is itself and anything OR 1 is 1

foo &= 0x01; // clear bit 0

Anything AND 1 is itself and anything AND 0 is 0

food ^= 0x01; // flip bit 0

Anything XOR 0 is itself and anything XOR 1 changes to its opposite (flips)

if (foo & 0x01) // Nonzero if the bit indicated by 0x01 is set
{
}

(0x01 << 2) = 00000100

(0x01 << 7) = 10000000

Macros:

#define b_get(p,m)      ((p) & (m))
#define b_set(p,m)      ((p) |= (m))
#define b_clear(p,m)    ((p) &= ~(m))
#define b_flip(p,m)     ((p) ^= (m))
#define b_write(c,p,m)  (c ? b_set(p,m) : b_clear(p,m))
#define bit(n)          (0x01 << (n))
#define longbit(n)      ((unsigned long)0x00000001 << (n))

b_set(foo, 0x01) // set a bit
b_set(foo, bit(5)) // set bit 5
b_clear(foo, bit(6)) // clear bit 6
b_flip(foo, bit(0_)
