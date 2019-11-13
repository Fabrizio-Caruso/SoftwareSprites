
#include <peekpoke.h>
#include <stdint.h>

#include "software_sprites.h"

static const uint8_t sprite_data[SPRITE_HEIGHT] = LUNAR_LANDER_DATA;

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

    loc = upper + SCREEN_START+(x&(0xF8))+((uint16_t) (y&(0xF8))<<3)*5; // (...<<6)*5 = *320
    {
        do
        {
            _display(loc,sprite_data[i],x&7);
            ++loc;
            ++i;
        } while (i<upper_end);
        loc+=312;
        for(;i<SPRITE_HEIGHT;++i,++loc)
        {
            _display(loc,sprite_data[i],x&7);            
        }
    }
}


