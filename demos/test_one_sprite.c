#include <stdint.h>
#include <conio.h>
#include "../src/software_sprites.h"

const uint8_t sprite_data[8] = { 24, 36, 24,102,153, 24, 36,102};

int main(void)
{
    uint16_t x;
    uint8_t y;
    uint8_t ch;
    
    bitmap_mode();
    
    clear_screen();
    
    y=0;
    while(1)
    {
        xor_sprite(sprite_data,x,y);
        ch=cgetc();
        xor_sprite(sprite_data,x,y);        
        if(ch=='j')
        {
            x-=1;
        }
        else if(ch=='l')
        {
            x+=1;
        }
        else if(ch=='i')
        {
            y-=1;
        }
        else if(ch=='k')
        {
            y+=1;
        }
        
    }
    while(1){};
    
    return 0;
}

