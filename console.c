#include <os.h>
#include <nspireio2.h>

void writeCharC(int x, int y, char ch, int color)
{
    putChar(x*6,y*8,ch,0,color);
}

void writeCharG(int x, int y, char ch)
{
    putChar(x*6,y*8,ch,0,15);
}

void writeStrC(int x, int y, char* str, int color)
{
    putStr(x*6,y*8,str,0,color);
}

void writeStrG(int x, int y, char* str)
{
    putStr(x*6,y*8,str,0,15);
}

void init(nio_console csl)
{
    lcd_ingray();
    clrscr();
    nio_InitConsole(&csl, 53, 29, 0, 0, 0, 15);
    nio_DrawConsole(&csl);
}

void cleanup(nio_console csl)
{
    nio_CleanUp(&csl);
}