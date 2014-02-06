#ifndef ROGUELIKE
#define ROGUELIKE

// roguelike.c
#define MAP_WIDTH   53
#define MAP_HEIGHT  29

#define TILE_FLOOR  0
#define TILE_WALL   1

int random(int);
void drawMap(int tiles[53][29]);
char getMapTile(int tiles[53][29], int,int);
int isPassable(int tiles[53][29], int,int);

// helper.c
void initRandom(void);
int random(int);
int median(int,int,int);
void printArray(int tiles[53][29]);

// console.h
void init(nio_console);
void cleanup(nio_console);

void writeCharC(int x, int y, char ch, int color);
void writeCharG(int x, int y, char ch);
void writeStrC(int x, int y, char* str, int color);
void writeStrG(int x, int y, char* str);

// worldbuilder.h
void randomizeTiles(int tiles[53][29], int);
void smooth(int tiles[53][29], int, int);
void makeCaves(int tiles[53][29]);

#endif