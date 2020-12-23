#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "constants.h"
#include "game.h"
#include "editor.h"



int main(int argc, char *argv[])
{
  SDL_Surface *screen = NULL, *menu = NULL;
  SDL_Rect menuPosition;
  SDL_Event event;

  int go_on = 1;

  SDL_Init(SDL_INIT_VIDEO);

  SDL_WM_SetIcon(IMG_Load("recipe.png"), NULL);
  screen = SDL_SetVideoMode(WIDTH_WINDOW, HEIGHT_WINDOW, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("Evil Bear", NULL);

  menu = IMG_Load("menu.png");
  menuPosition.x = 0;
  menuPosition.y = 0;
  
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
						go_on= 0;
                        break;
                    case SDLK_KP1:
                        play(screen);
                        break;
                    case SDLK_KP2:
                        editor(screen);
                        break;
                }
                break;
        }

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
        SDL_BlitSurface(menu, NULL, screen, &menuPosition);
        SDL_Flip(screen);
    }

    SDL_FreeSurface(menu);
    SDL_Quit();

    return EXIT_SUCCESS;
  
}
