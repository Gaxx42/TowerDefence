#include "imagehandler.h"



static SDL_Surface *screen;
static SDL_Surface *background;

void ih_cleanup()
{
    //Free the surfaces
    SDL_FreeSurface( background );
    SDL_FreeSurface( screen );
    //Quit SDL
    SDL_Quit();
}

void ih_clear_screen()
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    offset.x = 0;
    offset.y = 0;
    //Fill the screen black
    SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0x00, 0x00, 0x00 ) );
    //Set background
    SDL_BlitSurface( background, NULL, screen, &offset );
}

void ih_init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        //ERROR HANDLING
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        //ERROR HANDLING
    }

    //Set the window caption
    SDL_WM_SetCaption( "Tower defence", NULL );

}



void ih_update()
{
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
        //ERROR HANDLING
    }
}

void ih_draw_box(SDL_Rect *box, color_t color)
{
    SDL_Rect tbox;
    tbox.x = box->x;
    tbox.y = box->y;
    tbox.w = box->w;
    tbox.h = box->h;

    SDL_FillRect(   screen,
                    &tbox,
                    SDL_MapRGB( screen->format, color.r, color.g, color.b) );

}

