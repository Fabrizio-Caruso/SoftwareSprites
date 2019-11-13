
#include <peekpoke.h>
#include <stdint.h>

#include "software_sprites.h"

#define SCREEN_START ((uint16_t) 0x2000u)
#define SCREEN_END (SCREEN_START+8000)
#define LUMA_START 0x1800
#define LUMA_END (LUMA_START+1000)
#define CHROMA_START 0x1C00
#define CHROMA_END (CHROMA_START+1000)


static const uint8_t sprite_data[8] = {0x7E,0xC3,0x81,0xDB,0x7E,0x99,0x42,0xE7}; // Lunar lander


void bitmap_mode(void)
{
    // Set bitmap_mode
    POKE(0xFF06,PEEK(0xFF06)|32);
    
    // Set bitmap start at $2000
    POKE(0xFF12,PEEK(0xFF12)|8);
    POKE(0xFF12,PEEK(0xFF12)&(0xFF-16-32));    
    
    // Set luma/chroma at $1800 and $1C00
    POKE(0xFF14,PEEK(0xFF14)|(8+16));
    POKE(0xFF14,PEEK(0xFF14)&(0xFF-32-64-128));
    
    // Set luma/chroma background color
    // POKE(0xFF15,255);
}


void clear_screen(void)
{
    unsigned short i;
    
    for(i=SCREEN_START;i<SCREEN_END;++i)
    {
        POKE(i,0);
    }
    for(i=LUMA_START;i<LUMA_END;++i)
    {
        POKE(i,7);
    }
    for(i=CHROMA_START;i<CHROMA_END;++i)
    {
        POKE(i,0xFF-1);
    }
    
}


void _display(register uint16_t loc, uint8_t data, uint8_t offset)
{
    POKE(loc,PEEK(loc)^(data>>offset));
    if(offset)
    {
        loc+=8;
        POKE(loc,PEEK(loc)^(data<<(8-offset)));
    }    
}


void xor_sprite(uint8_t x, uint8_t y)
{
    uint16_t loc;
    uint8_t upper = y&7;
    uint8_t upper_end = 8-upper;
    uint8_t i = 0;    

    loc = upper + SCREEN_START+(x/8)*8+(uint16_t) (y>>3)*64*5;
    {
        do
        {
            _display(loc,sprite_data[i],x&7);
            ++loc;
            ++i;
        } while (i<upper_end);
        loc+=312;
        for(;i<8;++i,++loc)
        {
            _display(loc,sprite_data[i],x&7);            
        }
    }
}


