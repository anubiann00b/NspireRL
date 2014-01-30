#include <roguelike.h>
#include <helper.h>

void randomizeTiles(int tiles[MAP_WIDTH][MAP_HEIGHT], int chanceOfFloor)
{
    int x;
    for (x = 0; x < MAP_WIDTH; x++)
    {
        int y;
        for (y = 0; y < MAP_HEIGHT; y++)
        {
            tiles[x][y] = random(100) < chanceOfFloor ? TILE_FLOOR : TILE_WALL;
        }
    }
}

void smooth(int tiles[MAP_WIDTH][MAP_HEIGHT], int times, int liveAmount)
{
    int tiles2[MAP_WIDTH][MAP_HEIGHT];

    int time;
    for (time = 0; time < times; time++)
    {
        int x;
        for (x = 0; x < MAP_WIDTH; x++)
        {
            int y;
            for (y = 0; y < MAP_HEIGHT; y++)
            {
            int floors = 0;
            int walls = 0;

            int ox;
            for (ox = -1; ox < 2; ox++)
            {
                int oy;
                for (oy = -1; oy < 2; oy++)
                {
                    if (x + ox < 0 || x + ox >= MAP_WIDTH || y + oy < 0 || y + oy >= MAP_HEIGHT)
                        continue;
                    if (tiles[x + ox][y + oy] == TILE_FLOOR)
                        floors++;
                    else
                        walls++;
                }
            }
            if (walls >= liveAmount)
            {
                tiles2[x][y] = TILE_WALL;
            }
            else if (walls == 0)
            {
                tiles2[x][y] = TILE_WALL;
            }
            else
            {
                tiles2[x][y] = TILE_FLOOR;
            }
            tiles2[x][y] = floors >= walls ? TILE_FLOOR : TILE_WALL;
            }
        }
        tiles = tiles2;
    }
}

void makeCaves(int tiles[MAP_WIDTH][MAP_HEIGHT])
{
    randomizeTiles(tiles,55);
    smooth(tiles,5,5);
}