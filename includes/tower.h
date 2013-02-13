#ifndef TOWER_H
#define TOWER_H

#include "SDL.h"
#include "imagehandler.h"
#include "state_machine.h"
#include "enemy.h"

#define TOWER_SIZE 20
#define RANGE_SIZE 150

#define TOWER_COOLDOWN 15

class Tower
{
private:

    SDL_Rect    *tower;
    SDL_Rect    *range;
    int32_t     cooldown;
public:
                Tower();
                Tower(int32_t x, int32_t y);
                ~Tower();
    void        draw();
    SDL_Rect    *get_range();
    SDL_Rect    *get_box();
    int32_t     is_ready();
};

#endif // TOWER_H
