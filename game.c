#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "constants.h"
#include "files.h"
#include "game.h"

void play(SDL_Surface* screen)
{
    SDL_Surface *bear[4] = {NULL};
    SDL_Surface *wall = NULL, *recipe = NULL, *recipe_ready = NULL, *flame = NULL, *currentBear = NULL;
    SDL_Rect position, playerPosition;
    SDL_Event event;

    int go_on = 1, remainingObjectives = 0;
	int	i = 0, j = 0;
    int map[NB_BLOCKS_WIDTH][NB_BLOCKS_HEIGHT] = {0};

    wall = IMG_Load("wall.png");
    recipe = IMG_Load("recipe.png");
    recipe_ready = IMG_Load("recipe_ready.png");
    flame = IMG_Load("flame.png");
    bear[DOWN] = IMG_Load("bear_down.png");
    bear[GAUCHE] = IMG_Load("bear_left.png");
    bear[UP] = IMG_Load("bear_up.png");
    bear[RIGHT] = IMG_Load("bear_right.png");

    currentBear = bear[DOWN];

    if (!loadLevel(map))
        exit(EXIT_FAILURE);


    for (i = 0 ; i < NB_BLOCKS_WIDTH; i++)
    {
        for (j = 0 ; j < NB_BLOCKS_HEIGHT ; j++)
        {
            if (map[i][j] == BEAR)
            {
                playerPosition.x = i;
                playerPosition.y = j;
                map[i][j] = VOID;
            }
        }
    }


    SDL_EnableKeyRepeat(100, 100);

    while (go_on)
    {
        SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				go_on = 0;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						go_on = 0;
						break;
					case SDLK_UP:
						currentBear = bear[UP];
						movePlayer(map, &playerPosition, UP);
						break;
					case SDLK_DOWN:
						currentBear = bear[DOWN];
						movePlayer(map, &playerPosition, DOWN);
						break;
					case SDLK_RIGHT:
						currentBear = bear[RIGHT];
						movePlayer(map, &playerPosition, RIGHT);
						break;
					case SDLK_LEFT:
						currentBear = bear[LEFT];
						movePlayer(map, &playerPosition, LEFT);
						break;
				}
				break;
		}

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

        remainingObjectives = 0;

        for (i = 0 ; i < NB_BLOCKS_WIDTH ; i++)
        {
            for (j = 0 ; j < NB_BLOCKS_HEIGHT ; j++)
            {
                position.x = i * BLOCK_SIZE ;
                position.y = j * BLOCK_SIZE ;

                switch(map[i][j])
                {
                    case WALL:
                        SDL_BlitSurface(wall, NULL, screen, &position);
                        break;
                    case RECIPE:
                        SDL_BlitSurface(recipe, NULL, screen, &position);
                        break;
                    case RECIPE_READY:
                        SDL_BlitSurface(recipe_ready, NULL, screen, &position);
                        break;
                    case FLAME:
                        SDL_BlitSurface(flame, NULL, screen, &position);
                        remainingObjectives = 1;
                        break;
                }
            }
        }

        if (!remainingObjectives)
			go_on= 0;

        position.x = playerPosition.x * BLOCK_SIZE ;
        position.y = playerPosition.y * BLOCK_SIZE ;
        SDL_BlitSurface(currentBear, NULL, screen, &position);



        SDL_Flip(screen);
    }

    SDL_EnableKeyRepeat(0, 0);

    SDL_FreeSurface(wall);
    SDL_FreeSurface(recipe);
    SDL_FreeSurface(recipe_ready);
    SDL_FreeSurface(flame);
    for (i = 0 ; i < 4 ; i++)
        SDL_FreeSurface(bear[i]);
}

void movePlayer(int map[][NB_BLOCKS_HEIGHT], SDL_Rect *pos, int direction)
{
    switch(direction)
    {
        case UP:
            if (pos->y - 1 < 0) 
                break;
            if (map[pos->x][pos->y - 1] == WALL)
                break;

            if ((map[pos->x][pos->y - 1] == RECIPE || map[pos->x][pos->y - 1] == RECIPE_READY) &&
                (pos->y - 2 < 0 || map[pos->x][pos->y - 2] == WALL ||
                map[pos->x][pos->y - 2] == RECIPE || map[pos->x][pos->y - 2] == RECIPE_READY))
                break;

            
            moveRecipe(&map[pos->x][pos->y - 1], &map[pos->x][pos->y - 2]);

            pos->y--;
            break;


        case DOWN:
            if (pos->y + 1 >= NB_BLOCKS_HEIGHT)
                break;
            if (map[pos->x][pos->y + 1] == WALL)
                break;

            if ((map[pos->x][pos->y + 1] == RECIPE || map[pos->x][pos->y + 1] == RECIPE_READY) &&
                (pos->y + 2 >= NB_BLOCKS_HEIGHT || map[pos->x][pos->y + 2] == WALL ||
                map[pos->x][pos->y + 2] == RECIPE || map[pos->x][pos->y + 2] == RECIPE_READY))
                break;


            moveRecipe(&map[pos->x][pos->y + 1], &map[pos->x][pos->y + 2]);

            pos->y++;
            break;


        case LEFT:
            if (pos->x - 1 < 0)
                break;
            if (map[pos->x - 1][pos->y] == WALL)
                break;

            if ((map[pos->x - 1][pos->y] == RECIPE || map[pos->x - 1][pos->y] == RECIPE_READY) &&
                (pos->x - 2 < 0 || map[pos->x - 2][pos->y] == WALL ||
                map[pos->x - 2][pos->y] == RECIPE || map[pos->x - 2][pos->y] == RECIPE_READY))
                break;


            moveRecipe(&map[pos->x - 1][pos->y], &map[pos->x - 2][pos->y]);

            pos->x--;
            break;


        case RIGHT:
            if (pos->x + 1 >= NB_BLOCKS_WIDTH)
                break;
            if (map[pos->x + 1][pos->y] == WALL)
                break;

            if ((map[pos->x + 1][pos->y] == RECIPE || map[pos->x + 1][pos->y] == RECIPE_READY) &&
                (pos->x + 2 >= NB_BLOCKS_WIDTH || map[pos->x + 2][pos->y] == WALL ||
                map[pos->x + 2][pos->y] == RECIPE || map[pos->x + 2][pos->y] == RECIPE_READY))
                break;

            moveRecipe(&map[pos->x + 1][pos->y], &map[pos->x + 2][pos->y]);

            pos->x++;
            break;
    }
}

void moveRecipe(int *firstBox, int *secondBox)
{
    if (*firstBox == RECIPE || *firstBox == RECIPE_READY)
    {
        if (*secondBox == FLAME)
            *secondBox = RECIPE_READY;
        else
            *secondBox = RECIPE;

        if (*firstBox == RECIPE_READY)
            *firstBox = FLAME;
        else
            *firstBox = VOID;
    }
}
