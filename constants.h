#ifndef DEF_CONSTANTS
#define DEF_CONSTANTS

    #define BLOCK_SIZE  34 
    #define NB_BLOCKS_WIDTH    20
    #define NB_BLOCKS_HEIGHT    20
    #define HEIGHT_WINDOW     BLOCK_SIZE * NB_BLOCKS_HEIGHT
    #define WIDTH_WINDOW     BLOCK_SIZE * NB_BLOCKS_WIDTH


    enum {UP, DOWN, LEFT, RIGHT};
    enum {VOID, WALL, RECIPE, FLAME, BEAR, RECIPE_READY};

#endif
