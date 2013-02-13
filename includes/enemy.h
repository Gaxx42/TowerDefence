#ifndef ENEMY_H
#define ENEMY_H

#include "SDL.h"
#include "imagehandler.h"
#include "state_machine.h"
#include "log.h"

#define ENEMY_COOLDOWN  10;


class Enemy
{
private:

    SDL_Rect    *enemy;
    cell_t      position;
    int32_t     health;
    uint32_t    cooldown;
    uint32_t    direction;
public:
                Enemy();
                Enemy(uint32_t x, uint32_t y);
                ~Enemy();
    int32_t     move();
    uint8_t     hit(uint32_t damage);
    void        draw();
    SDL_Rect    *get_box();
};

#endif // ENEMY_H
