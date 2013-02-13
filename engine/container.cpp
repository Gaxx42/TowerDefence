#include "container.h"

node_tower_t    *curr_tower;
node_tower_t    *prev_tower;
node_tower_t    *head_tower = NULL;

node_enemy_t    *curr_enemy;
node_enemy_t    *prev_enemy;
node_enemy_t    *head_enemy = NULL;

node_particle_t *curr_particle;
node_particle_t *prev_particle;
node_particle_t *head_particle = NULL;

void    add_tower(Tower* element)
{
    // Create a new node
    node_tower_t *newNode = new node_tower_t;
    newNode->data = element;
    newNode->next = NULL;

    // Create a temp pointer
    node_tower_t *tmp = head_tower;
    if ( tmp != NULL )
    {
        // Nodes already present in the list
        // Parse to end of list
        while ( tmp->next != NULL ) {
            tmp = tmp->next;
        }

        // Point the last node to the new node
        tmp->next = newNode;
    }
    else
    {
        // First node in the list
        head_tower = newNode;
    }
}






void    add_enemy(Enemy* element)
{
    // Create a new node
    node_enemy_t *newNode = new node_enemy_t;
    newNode->data = element;
    newNode->next = NULL;

    // Create a temp pointer
    node_enemy_t *tmp = head_enemy;
    if ( tmp != NULL )
    {
        // Nodes already present in the list
        // Parse to end of list
        while ( tmp->next != NULL ) {
            tmp = tmp->next;
        }

        // Point the last node to the new node
        tmp->next = newNode;
    }
    else
    {
        // First node in the list
        head_enemy = newNode;
    }
}

void    add_particle(Particle* element)
{
    // Create a new node
    node_particle_t *newNode = new node_particle_t;
    newNode->data = element;
    newNode->next = NULL;

    // Create a temp pointer
    node_particle_t *tmp = head_particle;
    if ( tmp != NULL )
    {
        // Nodes already present in the list
        // Parse to end of list
        while ( tmp->next != NULL ) {
            tmp = tmp->next;
        }

        // Point the last node to the new node
        tmp->next = newNode;
    }
    else
    {
        // First node in the list
        head_particle = newNode;
    }
}

void start_over(entity_type_t type)
{
    switch(type)
    {
    case TOWER:
        curr_tower = head_tower;
        break;
    case ENEMY:
        curr_enemy = head_enemy;
        break;
    case PARTICLE:
        curr_particle = head_particle;
        break;
    }
}

void add(void *element, entity_type_t type)
{

    switch(type)
    {
    case TOWER:
        add_tower((Tower*)element);
        break;
    case ENEMY:
        add_enemy((Enemy*)element);
        break;
    case PARTICLE:
        add_particle((Particle*)element);
        break;
    default:
        break;
    }

}

void remove(entity_type_t type)
{
    switch(type)
    {
    case TOWER:
        if(curr_tower != head_tower)
        {
            prev_tower->next = curr_tower->next;
            delete      (curr_tower->data);
            delete[]    curr_tower;
            curr_tower = prev_tower->next;
        }
        else
        {
            delete      (curr_tower->data);
        }
        break;
    case ENEMY:
        if(curr_enemy != head_enemy)
        {
            prev_enemy->next = curr_enemy->next;
            delete      (curr_enemy->data);
            delete[]    curr_enemy;
            curr_enemy = prev_enemy->next;
        }
        else
        {
            delete      (curr_enemy->data);
        }
        break;
    case PARTICLE:
        if(curr_particle != head_particle)
        {
            prev_particle->next = curr_particle->next;
            delete      (curr_particle->data);
            delete[]    curr_particle;
            curr_particle = prev_particle->next;
        }
        break;
    }
}

void traverse(entity_type_t type)
{
    switch(type)
    {
    case TOWER:
        if(curr_tower != NULL)
        {
            prev_tower = curr_tower;
            curr_tower = curr_tower->next;
        }
        break;
    case ENEMY:
        if(curr_enemy != NULL)
        {
            prev_enemy = curr_enemy;
            curr_enemy = curr_enemy->next;
        }
        break;
    case PARTICLE:
        if(curr_particle != NULL)
        {
            prev_particle = curr_particle;
            curr_particle = curr_particle->next;
        }
        break;
    }
}

void  *get_curr(entity_type_t type)
{
    switch(type)
    {
    case TOWER:
        if(curr_tower != NULL)
        {
            return curr_tower->data;
        }
        else
        {
            return NULL;
        }
        break;
    case ENEMY:
        if(curr_enemy != NULL)
        {
            return curr_enemy->data;
        }
        else
        {
            return NULL;
        }
        break;
    case PARTICLE:
        if(curr_particle != NULL)
        {
            return curr_particle->data;
        }
        else
        {
            return NULL;
        }
        break;
    default:
        return 0;
    }

}


