#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include "SDL.h"
#include <string>
#include <stdlib.h>

#define BOX_SIZE        20

//The attributes of the screen
#define SCREEN_WIDTH    480
#define SCREEN_HEIGHT   480
#define SCREEN_BPP      32


typedef struct
{
    uint8_t    r;
    uint8_t    g;
    uint8_t    b;
}color_t;



    //Draws a rectangle. Not much to say here.
    void        ih_draw_box(SDL_Rect *box, color_t color);

    //Initialization
    void        ih_init();

    //Flip buffers
    void        ih_update();

    //Clean all buffers, free memory, etc
    void        ih_cleanup();

    //Fill screen black
    void        ih_clear_screen();


#endif // IMAGEHANDLER_H
