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
    int currentObject = WALL,
    int i = 0, j = 0;
    int map[NB_BLOCKS_WIDTH][NB_BLOCS_HEIGHT] = {0};

    wall = IMG_Load("wall.png");
    recipe = IMG_Load("recipe.png");
    flame = IMG_Load("flame.png");
    bear = IMG_Load("bear_down.png");

}
