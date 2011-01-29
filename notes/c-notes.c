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

Anything OR'd with 0 is itself and anything OR'd with 1 is 1

foo &= 0x01; // clear bit 0

Anything AND'd with 1 is itself and anything AND's with 0 is 0
