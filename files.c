
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "constants.h"
#include "files.h"

int loadLevel(int level[][NB_BLOCKS_HEIGHT])
{
    FILE* file = NULL;
    char lineFile[NB_BLOCKS_WIDTH * NB_BLOCKS_HEIGHT + 1] = {0};
    int i = 0;
	int j = 0;

    file = fopen("Levels", "r");
    if (file == NULL) return 0;

    fgets(lineFile, NB_BLOCKS_WIDTH * NB_BLOCKS_HEIGHT + 1, file);

    for (i = 0 ; i < NB_BLOCKS_WIDTH ; i++)
    {
        for (j = 0 ; j < NB_BLOCKS_HEIGHT ; j++)
        {
            switch (lineFile[(i * NB_BLOCKS_WIDTH) + j])
            {
                case '0':              //0: void
                    level[j][i] = 0;
                    break; 
                case '1':              //1: wall
                    level[j][i] = 1;
                    break;
                case '2':              //2: recipe
                    level[j][i] = 2;
                    break;
                case '3':              //3: flame
                    level[j][i] = 3;
                    break;
                case '4':              //4: bear
                    level[j][i] = 4;
                    break;
            }
        }
    }

    fclose(file);
    return 1;
}

int saveLevel(int level[][NB_BLOCKS_HEIGHT])
{
    FILE* file = NULL;
    int i = 0, j = 0;

    file = fopen("Levels", "w");
    if (file == NULL) return 0;

    for (i = 0 ; i < NB_BLOCKS_WIDTH ; i++)
    {
        for (j = 0 ; j < NB_BLOCKS_HEIGHT ; j++)
        {
            fprintf(file, "%d", level[j][i]);
        }
    }

    fclose(file);
    return 1;
}
