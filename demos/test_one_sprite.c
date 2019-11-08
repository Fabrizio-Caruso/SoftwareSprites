#include <stdint.h>
#include <conio.h>
#include "../src/software_sprites.h"

const uint8_t sprite_data[8] = { 24, 36, 24,102,153, 24, 36,102};

int main(void)
{
    uint16_t i;
    
    bitmap_mode();
    
    clear_screen();
    
    i=0;
    while(1)
    {
        xor_sprite(sprite_data,8*i,32);
        cgetc();
        xor_sprite(sprite_data,8*i,32);        
        i+=8;
    }
    while(1){};
    
    return 0;
}

