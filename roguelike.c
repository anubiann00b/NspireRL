#include <os.h>
#include <nspireio2.h>
#include <console.h>
#include <roguelike.h>
#include <helper.h>
#include <worldbuilder.h>

int mapArray[MAP_HEIGHT][MAP_WIDTH];

int main(void)
{
	int playerX=2, playerY=10;
    nio_console csl;
	init(csl);
    makeCaves(mapArray);
	drawMap();
	writeCharG(playerX,playerY,'@');
	while(!isKeyPressed(KEY_NSPIRE_ESC))
	{
		int dx=0;
        int dy=0;
		if (isKeyPressed(KEY_NSPIRE_8) || isKeyPressed(KEY_NSPIRE_UP))
		{
			dy=-1;
		}
		else if (isKeyPressed(KEY_NSPIRE_2) || isKeyPressed(KEY_NSPIRE_DOWN))
		{
			dy=1;
		}
		else if (isKeyPressed(KEY_NSPIRE_4) || isKeyPressed(KEY_NSPIRE_LEFT))
		{
			dx=-1;
		}
		else if (isKeyPressed(KEY_NSPIRE_6) || isKeyPressed(KEY_NSPIRE_RIGHT))
		{
			dx=1;
		}
        else if (isKeyPressed(KEY_NSPIRE_1))
        {
            dx=-1;
            dy=1;
        }
        else if (isKeyPressed(KEY_NSPIRE_3))
        {
            dx=1;
            dy=1;
        }
        else if (isKeyPressed(KEY_NSPIRE_7))
        {
            dx=-1;
            dy=-1;
        }
        else if (isKeyPressed(KEY_NSPIRE_9))
        {
            dx=1;
            dy=-1;
        }
		if(isPassable(playerX+dx,playerY+dy))
        {
			playerX+=dx;
			playerY+=dy;
		}
		if (dx!=0 || dy!=0)
		{
			writeCharG(playerX,playerY,'@');
			writeCharG(playerX-dx,playerY-dy,getMapTile(playerX-dx,playerY-dy));
		}
	}
    cleanup(csl);
	return 0;
}

int isPassable(int x, int y)
{
    if(x<0 || x>=MAP_WIDTH || y<0 || y>=MAP_HEIGHT)
        return 0;
    if(mapArray[y][x] == TILE_FLOOR)
        return 1;
    return 0;
}

char getMapTile(int x, int y)
{
	if(mapArray[y][x]==TILE_FLOOR)
	{
		return '.';
	}
	else if(mapArray[y][x]==TILE_WALL)
	{
		return '#';
	}
	else
	{
		return 'x';
	}
}

void drawMap(void)
{
	int x,y;
    for(y=0;y<MAP_HEIGHT;y++)
    {
        for (x=0;x<MAP_WIDTH;x++)
        {
			writeCharG(x,y,getMapTile(x,y));
        }
    }
}
