
#define MAP_WIDTH   53
#define MAP_HEIGHT  29

#define TILE_FLOOR  0
#define TILE_WALL   1

int random(int);
void drawMap(void);
char getMapTile(int,int);
int isPassable(int,int);
