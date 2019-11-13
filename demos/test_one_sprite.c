#include <stdint.h>
#include <conio.h>
#include "../src/software_sprites.h"

int main(void)
{
    uint8_t ch;
    uint8_t x = 100;
    uint8_t y = 90;
    
    bitmap_mode();
    
    clear_screen();
    
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

