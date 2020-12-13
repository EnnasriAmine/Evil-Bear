#ifndef DEF_GAME
#define DEF_GAME

    void play(SDL_Surface* screen);
    void movePlayer(int map[][NB_BLOCKS_HEIGHT], SDL_Rect *pos, int direction);
    void moveRecipe(int *firstBox, int *secondBox);


#endif
