#include "game.h"

//The event structure
SDL_Event   event;

Enemy       *tmpenemy   = 0;
Particle    *tmppart    = 0;
Tower       *tmptower   = 0;
int32_t     move_result = 0;
int32_t     game_over   = 0;
int32_t     shoot_flag  = 0;
int32_t     ready_flag = 0;


void handle_events()
{

    //The mouse offsets
    int32_t x = 0;
    int32_t y = 0;


    x = event.button.x;
    y = event.button.y;

    //If a mouse button was pressed
    if( event.type == SDL_MOUSEBUTTONDOWN )
    {
        //If the left mouse button was pressed
        if( event.button.button == SDL_BUTTON_LEFT )
        {

        }
        //If the right mouse button was pressed
        if( event.button.button == SDL_BUTTON_RIGHT )
        {

        }
    }
    else if( event.type == SDL_MOUSEBUTTONUP )
    {
        //If the left mouse button was pressed
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            add(new Tower(x,y), TOWER);
        }
        //If the right mouse button was pressed
        if( event.button.button == SDL_BUTTON_RIGHT )
        {

        }
    }


}


void run_game()
{
    //This is a main game

        //Quit flag
        bool quit = false;

        //The frame rate regulator
        Timer fps;

        ih_init();
        srand(time(NULL));
        add(new Enemy(50,50), ENEMY);
        add(new Particle(), PARTICLE);
        add(new Tower(), TOWER);

        //main loop
        while(quit == false)
        {
            //Start the frame timer
            fps.start();

            //While there's events to handle
            while( SDL_PollEvent( &event ) )
            {
                handle_events();
                //If the user has Xed out the window
                if( event.type == SDL_QUIT )
                {
                    //Quit the program
                    quit = true;
                }
            }


            if((rand()%100) < 5)
            {
                add(new Enemy(), ENEMY);
            }


            //MOVES
            //=====Enemy
            start_over(ENEMY);
            while(get_curr(ENEMY))
            {
                tmpenemy = (Enemy*)get_curr(ENEMY);
                if(tmpenemy != NULL)
                {
                    LOG("Calling tmpenemy->move()\n");
                    move_result = tmpenemy->move();
                }
                if(move_result == -1)
                {
                    LOG("Enemy removed\n");
                    remove(ENEMY);
                    game_over = hit();
                    if(game_over)
                    {
                        quit = true;
                    }
                }
                traverse(ENEMY);
            }

            //=====Particle
            start_over(PARTICLE);
            while(get_curr(PARTICLE))
            {
                tmppart = (Particle*)get_curr(PARTICLE);
                if(tmppart != NULL)
                {
                    LOG("Calling tmppart->move()\n");
                    move_result = tmppart->move();
                }
                if(move_result == -1)
                {
                    LOG("Particle removed\n");
                    remove(PARTICLE);
                }
                traverse(PARTICLE);
            }

            //=====Tower
            start_over(TOWER);
            while(get_curr(TOWER))
            {
                tmptower = (Tower*)get_curr(TOWER);
                if(tmptower != NULL)
                {
                    ready_flag = tmptower->is_ready();
                    //find target, shoot, hit, create particle
                    start_over(ENEMY);
                    while(get_curr(ENEMY))
                    {
                        tmpenemy = (Enemy*)get_curr(ENEMY);
                        if(tmpenemy != NULL)
                        {
                            if(check_collision(tmpenemy->get_box(), tmptower->get_range()))
                            {
                                LOG("Target locked!\n");
                                if(ready_flag)
                                {
                                    add(new Particle(tmptower->get_box(), tmpenemy->get_box()), PARTICLE);

                                    if(tmpenemy->hit(10))
                                    {
                                        LOG("Enemy killed!\n");
                                        remove(ENEMY);
                                    }

                                }
                            }
                        }

                        traverse(ENEMY);
                    }
                }
                traverse(TOWER);
            }


            //CLS
            ih_clear_screen();


            //DRAWING
            //=====Enemy
            start_over(ENEMY);
            while(get_curr(ENEMY))
            {
                tmpenemy = (Enemy*)get_curr(ENEMY);
                if(tmpenemy != NULL)
                {
                    tmpenemy->draw();
                }

                traverse(ENEMY);
            }

//            //=====Particle
            start_over(PARTICLE);
            while(get_curr(PARTICLE))
            {
                tmppart = (Particle*)get_curr(PARTICLE);
                if(tmppart != NULL)
                {
                    tmppart->draw();
                }

                traverse(PARTICLE);
            }

//            //=====Tower
            start_over(TOWER);
            while(get_curr(TOWER))
            {
                tmptower = (Tower*)get_curr(TOWER);
                if(tmptower != NULL)
                {
                    tmptower->draw();
                }

                traverse(TOWER);
            }


            ih_update();

            //Cap the frame rate
            if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
            {
                SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
            }

        }

        ih_cleanup();

}
