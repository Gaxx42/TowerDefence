#ifndef CONTAINER_H
#define CONTAINER_H

#include "enemy.h"
#include "tower.h"
#include "particle.h"

//Node of a linked list
struct node_tower
{
    Tower                   *data;
    struct node_tower       *next;
};
typedef struct node_tower node_tower_t;

struct node_enemy
{
    Enemy                   *data;
    struct node_enemy       *next;
};
typedef struct node_enemy node_enemy_t;


struct node_particle
{
    Particle                *data;
    struct node_particle    *next;
};
typedef struct node_particle node_particle_t;


typedef enum
{
    TOWER,
    ENEMY,
    PARTICLE
}entity_type_t;



//Starts linked list from beginning
void    start_over(entity_type_t type);

//Adds element to linked list
void    add(void *element, entity_type_t type);

//removes element
void    remove(entity_type_t type);

//Next element
void    traverse(entity_type_t type);

//Get current node
void     *get_curr(entity_type_t type);

#endif // CONTAINER_H
