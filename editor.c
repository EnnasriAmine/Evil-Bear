#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "constants.h"
#include "editor.h"
#include "files.h"

void editor(SDL_Surface* screen)
{
    SDL_Surface *wall = NULL, *recipe = NULL, *flame = NULL, *bear = NULL;
    SDL_Rect position;
    SDL_Event event;

    int go_on = 1;
    int LeftclickOngoing = 0;
    int RightclickOngoing = 0;
    int currentObject = WALL;
    int i = 0, j = 0;
    int map[NB_BLOCKS_WIDTH][NB_BLOCS_HEIGHT] = {0};

    wall = IMG_Load("wall.png");
    recipe = IMG_Load("recipe.png");
    flame = IMG_Load("flame.png");
    bear = IMG_Load("bear_down.png");
    
    if (!loadLevel(map))
        exit(EXIT_FAILURE);

    while (go_on)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                go_on = 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    map[event.button.x / BLOCK_SIZE][event.button.y / BLOCK_SIZE] = currentObject;
                    LeftclickOngoing = 1;
                }
                else if (event.button.button == SDL_BUTTON_RIGHT)
                {
                    map[event.button.x / BLOCK_SIZE][event.button.y /BLOCK_SIZE] = VIDE;
                    RightclickOngoin = 1;
                }
                break;
            case SDL_MOUSEBUTTONUP: 
                if (event.button.button == SDL_BUTTON_LEFT)
                    LeftclickOngoing = 0;
                else if (event.button.button == SDL_BUTTON_RIGHT)
                    RightclickOngoin = 0;
                break;
            case SDL_MOUSEMOTION:
                if (LeftclickOngoing)
                {
                    map[event.motion.x / BLOCK_SIZE][event.motion.y / BLOCK_SIZE] = currentObject;
                }
                else if (RightclickOngoin) 
                {
                    map[event.motion.x / BLOCK_SIZE][event.motion.y /BLOCK_SIZE] = VIDE;
                }
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        go_on = 0;
                        break;
                    case SDLK_s:
                        saveLevel(map);
                        break;
                    case SDLK_c:
                        loadLevel(map);
                        break;
                    case SDLK_KP1:
                        currentObject = WALL;
                        break;
                    case SDLK_KP2:
                        currentObject = RECIPE;
                        break;
                    case SDLK_KP3:
                        currentObject = FLAME;
                        break;
                    case SDLK_KP4:
                        currentObject = BEAR;
                        break;
                }
                break;
        }


        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

}
