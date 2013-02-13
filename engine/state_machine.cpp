#include "state_machine.h"

static cell_t rotation_nodes[NODE_NUMBER] = {
    {4 ,21},
    {9 ,21},
    {9 ,1},
    {14,1},
    {14,21},
    {18,21},
    {18,1},
    {23,1}
};

static int32_t directions[NODE_NUMBER] = {
    RIGHT,
    UP,
    RIGHT,
    DOWN,
    RIGHT,
    UP,
    RIGHT,
    END
};

static int32_t num_of_hits = NUMBER_OF_HITS;


int32_t    is_rotation_node(cell_t cell)
{
    int32_t i = 0;
    for(i = 0; i < NODE_NUMBER; i++)
    {
        if((cell.x == rotation_nodes[i].x) && (cell.y == rotation_nodes[i].y))
        {
            return directions[i];
        }
    }
    return 0;
}

int32_t hit()
{
    num_of_hits--;
    LOG("Hits left: %d\n", num_of_hits);
    if(num_of_hits <= 0)
    {
        return 1;
    }
    return 0;
}

bool check_collision( SDL_Rect *A, SDL_Rect *B )
{
    //The sides of the rectangles
    int32_t leftA, leftB;
    int32_t rightA, rightB;
    int32_t topA, topB;
    int32_t bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A->x;
    rightA = A->x + A->w;
    topA = A->y;
    bottomA = A->y + A->h;

    //Calculate the sides of rect B
    leftB = B->x;
    rightB = B->x + B->w;
    topB = B->y;
    bottomB = B->y + B->h;

    //If any of the sides from A are outside of B
    if( bottomA < topB )
    {
        return false;
    }

    if( topA > bottomB )
    {
        return false;
    }

    if( rightA < leftB )
    {
        return false;
    }

    if( leftA > rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}
