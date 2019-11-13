#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../src/software_sprites.h"

#define DOUBLE_XOR_LOOPS 190

int main(void)
{
    clock_t Ticks, TicksDelta;
    unsigned int Sec;
    unsigned int Milli; 
    
    uint8_t x;

    while(1)
    {
        printf("\nPress enter to start\n");
        getchar();
        printf("\nComputing...\n"); 
        Ticks = clock();    
        for(x=0;x<DOUBLE_XOR_LOOPS;++x)
        {
            xor_sprite(x,x);
            xor_sprite(x,x);
        }
          
        TicksDelta = clock() - Ticks;
        Sec = (unsigned short) (TicksDelta / CLOCKS_PER_SEC);
        Milli = ((TicksDelta % CLOCKS_PER_SEC) * 1000) / CLOCKS_PER_SEC;
        printf ("Time used: %u.%03u seconds = %u ticks\n", Sec, Milli, (unsigned short) TicksDelta);   
        
    };
    return 0;
}

