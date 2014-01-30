#include <stdlib.h>

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
