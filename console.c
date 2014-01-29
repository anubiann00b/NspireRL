#include <os.h>
#include <nspireio2.h>

void init(nio_console csl)
{
    lcd_ingray();
    clrscr();
    nio_InitConsole(&csl, 53, 29, 0, 0, 0, 15);
    nio_DrawConsole(&csl);
}

void cleanUp(nio_console csl)
{
    nio_CleanUp(&csl);
}