
#include <peekpoke.h>
#include <stdint.h>

#include "software_sprites.h"

#define SCREEN_START 0x2000
#define SCREEN_END (SCREEN_START+8000)
#define LUMA_START 0x1800
#define LUMA_END (LUMA_START+1000)
#define CHROMA_START 0x1C00
#define CHROMA_END (CHROMA_START+1000)


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

void xor_sprite(const uint8_t* sprite_data, uint16_t x, uint8_t y)
{
    uint8_t i;
    uint16_t loc;
    
    uint8_t j;
    
    for(j=0;j<8;++j)
    {
        for(i=0;i<8;++i)
        {
            POKE(SCREEN_START+8*j+i,sprite_data[i]);
        }
    }
    // if(x%8==0)
    // {
        // if(y%8==0)
        // {
            // for(i=0;i<8;++i)
            // {
                // loc = SCREEN_START+(x/8)*(y/8)*320;
                // POKE(loc,PEEK(loc)^sprite_data[i]);
            // }
        // }
    // }
}




