#include <os.h>
#include <nspireio2.h>
#include <roguelike.h>

static int mapArray[MAP_WIDTH][MAP_HEIGHT];

int main(void)
{
	int playerX=2, playerY=10;
	nio_console csl;
	initRandom();
	init(csl);

	makeCaves(mapArray);

	drawMap(mapArray);

	writeCharG(playerX,playerY,'@');

	while(!isKeyPressed(KEY_NSPIRE_0))
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
		if(isPassable(mapArray, playerX+dx,playerY+dy))
		{
			playerX+=dx;
			playerY+=dy;
		}
		if (dx!=0 || dy!=0)
		{
			writeCharG(playerX,playerY,'@');
			writeCharG(playerX-dx,playerY-dy,getMapTile(mapArray,playerX-dx,playerY-dy));
		}
	}
	cleanup(csl);
	return 0;
}

int isPassable(int tiles[MAP_WIDTH][MAP_HEIGHT], int x, int y)
{
	if(x<0 || x>=MAP_WIDTH || y<0 || y>=MAP_HEIGHT)
		return 0;
	if(tiles[x][y] == TILE_FLOOR)
		return 1;
	return 0;
}

char getMapTile(int tiles[MAP_WIDTH][MAP_HEIGHT], int x, int y)
{
	if(tiles[x][y]==TILE_FLOOR)
	{
		return '.';
	}
	else if(tiles[x][y]==TILE_WALL)
	{
		return '#';
	}
	else
	{
		return 'x';
	}
}

void drawMap(int tiles[MAP_WIDTH][MAP_HEIGHT])
{
	int x,y;
	for(y=0;y<MAP_HEIGHT;y++)
	{
		for (x=0;x<MAP_WIDTH;x++)
		{
			writeCharG(x,y,getMapTile(tiles,x,y));
		}
	}
}
