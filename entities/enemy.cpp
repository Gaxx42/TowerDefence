#include "enemy.h"

Enemy::Enemy()
{
    LOG("New enemy created\n");

    enemy       = new SDL_Rect();
    position.x  = 4;
    position.y  = 0;
    health      = 100;
    cooldown    = ENEMY_COOLDOWN;
    direction   = DOWN;
    enemy->x    = position.x * BOX_SIZE;
    enemy->y    = position.y * BOX_SIZE;
    enemy->h    = BOX_SIZE;
    enemy->w    = BOX_SIZE;
}

Enemy::Enemy(uint32_t x, uint32_t y)
{
    LOG("New enemy created\n");

    enemy       = new SDL_Rect();
    position.x  = x;
    position.y  = y;
    health      = 100;
    cooldown    = ENEMY_COOLDOWN;
    direction   = DOWN;
    enemy->x    = position.x * BOX_SIZE;
    enemy->y    = position.y * BOX_SIZE;
    enemy->h    = BOX_SIZE;
    enemy->w    = BOX_SIZE;
}

Enemy::~Enemy()
{

}

int32_t        Enemy::move()
{
    uint32_t direction_tmp;

    cooldown--;
    if(cooldown == 0)
    {
        switch(direction)
        {
        case UP:
            position.y--;
            break;
        case DOWN:
            position.y++;
            break;
        case RIGHT:
            position.x++;
            break;
        case LEFT:
            position.x--;
            break;
        case END:
            LOG("We reached end\n");
            return -1;
            break;
        }
        enemy->x = position.x * BOX_SIZE;
        enemy->y = position.y * BOX_SIZE;

        LOG("Enemy moved to x:%d, y:%d\n", position.x, position.y);

        direction_tmp = is_rotation_node(position);

        if(direction_tmp)
        {
            direction = direction_tmp;
        }
        LOG("Direction: %d\n", direction);

        cooldown = ENEMY_COOLDOWN;
    }
    return 0;
}

void        Enemy::draw()
{
    color_t color = {0xA5, 0x22, 0x22};
    ih_draw_box(enemy, color);
}

uint8_t     Enemy::hit(uint32_t damage)
{
    health -= damage;
    if(health <= 0)
    {
        return 1;
    }
    return 0;
}

SDL_Rect *Enemy::get_box()
{
    return enemy;
}
