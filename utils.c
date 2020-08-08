#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "utils.h"


int random()
{
    srand(time(0));
    double pEntiere = (rand() % 15) + 35;
    double pDecimale = (rand() % 999);
    pDecimale /= 1000;
    double temps = pEntiere + pDecimale;
    printf("%f", temps);

    return 0;
}
