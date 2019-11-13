#ifndef _SOFTWARE_SPRITE_H
#define _SOFTWARE_SPRITE_H

#include <peekpoke.h>
#include <stdint.h>

#include "software_sprites.h"


void bitmap_mode(void);

void clear_screen(void);

void xor_sprite(uint16_t x, uint8_t y);


#endif // _SOFTWARE_SPRITE_H



