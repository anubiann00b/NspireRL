#include <stdlib.h>
#include <stdio.h>
#include <roguelike.h>

void initRandom(void)
{
    srand(time(NULL));
}

int random(int max)
{
    return (rand() % max);
}

int median(int A, int B, int C)
{
    if ((A-B)*(C-A)>=0)
    {
        return A;
    }
    else if ((B-A)*(C-B)>=0)
    {
        return B;
    }
    else
    {
        return C;
    }
}

void printArray(int tiles[MAP_WIDTH][MAP_HEIGHT])
{
    int i,j;
    for (i=0;i<MAP_HEIGHT;i++)
    {
        for (j=0;j<MAP_WIDTH;j++)
        {
            if (tiles[i][j] == 0)
                printf(".");
            else if (tiles[i][j] == 1)
                printf("#");
            else
                printf("Q");
        }
        printf("\n");
    }
    printf("\n-----------------------------------\n");
}
