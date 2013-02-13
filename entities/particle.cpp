#include "particle.h"

Particle::Particle()
{
    particle       = new SDL_Rect();
    destination    = new SDL_Rect();
}

Particle::Particle(SDL_Rect *src, SDL_Rect *dst)
{
    particle       = new SDL_Rect();
    destination    = new SDL_Rect();

    particle->x = src->x;
    particle->y = src->y;
    particle->w = PARTICLE_SIZE;
    particle->h = PARTICLE_SIZE;

    destination->x = dst->x;
    destination->y = dst->y;
    destination->w = DEST_SIZE;
    destination->h = DEST_SIZE;

    x_velocity = (destination->x - particle->x)/5;
    y_velocity = (destination->y - particle->y)/5;

}

Particle::~Particle()
{

}

void        Particle::draw()
{
    color_t color = {0x22, 0x22, 0xA2};
    ih_draw_box(particle, color);
}

int32_t       Particle:: move()
{
    particle->x += x_velocity;
    particle->y += y_velocity;

    if(check_collision(particle, destination))
    {
        return -1;
    }
    return 0;
}
