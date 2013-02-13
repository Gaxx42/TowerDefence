#ifndef PARTICLE_H
#define PARTICLE_H

#include "SDL.h"
#include "imagehandler.h"
#include "state_machine.h"

#define PARTICLE_SIZE   5
#define DEST_SIZE       50

class Particle
{
private:

    SDL_Rect    *particle;
    SDL_Rect    *destination;
    uint32_t    x_velocity;
    uint32_t    y_velocity;
    cell_t      dest;
public:
                Particle();
                Particle(SDL_Rect *src, SDL_Rect *dst);
                ~Particle();
    int32_t     move();
    void        draw();
};

#endif // PARTICLE_H
