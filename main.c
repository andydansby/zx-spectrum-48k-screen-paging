//main.c

//for 48k & 128k speccy only

//z88dk compile string
//zcc +zx -vn -O3 -zorg=24600 main.c  -lndos -o -create-app -m

#include "compress.h"
#include "spectrum.h"
//used for zx_border and in_Pause

extern unsigned char screen1[];
#asm
	._screen1
		BINARY "screen1.bin"
#endasm

extern unsigned char screen2[];
#asm
	._screen2
		BINARY "screen2.bin"
#endasm

//copied from the mojon twins MK2 engine
void blackout (void) {
	#asm
		ld hl, 22528
		ld (hl), 0
		push hl
		pop de
		inc de
		ld bc, 767
		ldir
	#endasm
}

void main(void)
{
	blackout();	
	zx_border(0);

	while (1)
	{
		unpack ((unsigned int) (screen1), 16384);
	
		in_Pause(500);//in milliseconds
	
		unpack ((unsigned int) (screen2), 16384);
		in_Pause(500);
	}	
}




