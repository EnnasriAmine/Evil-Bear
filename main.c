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
  
}
