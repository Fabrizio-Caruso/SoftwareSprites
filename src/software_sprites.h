#ifndef _SOFTWARE_SPRITE_H
#define _SOFTWARE_SPRITE_H

#include <peekpoke.h>
#include <stdint.h>

#if !defined(SCREEN_START)
    #define SCREEN_START ((uint16_t) 0x2000u)
#endif
#define SCREEN_END (SCREEN_START+8000)
#define LUMA_START 0x1800
#define LUMA_END (LUMA_START+1000)
#define CHROMA_START 0x1C00
#define CHROMA_END (CHROMA_START+1000)

// #define SPRITE_HEIGHT 9
// #define LUNAR_LANDER_DATA {0x18, 0x7E,0xC3,0x81,0xDB,0x7E,0x99,0x42,0xE7}

#define SPRITE_HEIGHT 8
#define LUNAR_LANDER_DATA {0x7E,0xC3,0x81,0xDB,0x7E,0x99,0x42,0xE7}

void bitmap_mode(void);

void clear_screen(void);

void xor_sprite(uint8_t x, uint8_t y);


#endif // _SOFTWARE_SPRITE_H



