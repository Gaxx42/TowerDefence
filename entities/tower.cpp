#include "tower.h"

Tower::Tower()
{
    tower   = new SDL_Rect();
    range   = new SDL_Rect();
}

Tower::Tower(int32_t x, int32_t y)
{
    tower   = new SDL_Rect();
    range   = new SDL_Rect();

    tower->x = x;
    tower->y = y;
    tower->w = TOWER_SIZE;
    tower->h = TOWER_SIZE;

    range->x = x + TOWER_SIZE/2 - RANGE_SIZE/2;
    range->y = y + TOWER_SIZE/2 - RANGE_SIZE/2;
    range->w = RANGE_SIZE;
    range->h = RANGE_SIZE;
    cooldown = TOWER_COOLDOWN;

}

Tower::~Tower()
{

}


void        Tower::draw()
{
    color_t color = {0x22, 0xA2, 0x22};
    ih_draw_box(tower, color);
}

SDL_Rect    *Tower::get_range()
{
    return range;
}

SDL_Rect    *Tower::get_box()
{
    return tower;
}

int32_t     Tower::is_ready()
{
    cooldown--;
    if(cooldown <= 0)
    {
        LOG("Ready to shoot\n");
        cooldown = TOWER_COOLDOWN;
        return 1;
    }
    return 0;
}
