#include <stdint.h>

#include "../src/software_sprites.h"

const uint8_t sprite_data[8] = { 24, 36, 24,102,153, 24, 36,102};

int main(void)
{
    bitmap_mode();
    
    clear_screen();
    
    xor_sprite(sprite_data,0,0);
    
    while(1){};
    
    return 0;
}

