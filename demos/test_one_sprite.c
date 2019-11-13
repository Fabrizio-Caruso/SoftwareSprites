#include <stdint.h>
#include <conio.h>
#include "../src/software_sprites.h"

int main(void)
{
    uint8_t x;
    uint8_t y;
    uint8_t ch;
    
    bitmap_mode();
    
    clear_screen();
    
    y=0;
    while(1)
    {
        xor_sprite(x,y);
        ch=cgetc();
        xor_sprite(x,y);        
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

