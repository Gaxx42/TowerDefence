#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "SDL.h"
#include "log.h"

#define UP      1
#define DOWN    2
#define RIGHT   3
#define LEFT    4

#define END     5

#define NODE_NUMBER     8

#define NUMBER_OF_HITS  10

typedef struct
{
    uint32_t x;
    uint32_t y;
}cell_t;

int32_t     is_rotation_node(cell_t cell);
int32_t     hit();
bool check_collision( SDL_Rect *A, SDL_Rect *B );

#endif // STATE_MACHINE_H
