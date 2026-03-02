#ifndef SHOW_H
#define SHOW_H

#include "Constants.h"

struct Show
{
    int id;
    int movieId;

    char datetime[MAX_DATETIME];
    int price;

    unsigned char seats[ROWS][COLS];
    int availableCount;

    void *bookingIdListHead;
    void *waitFront;
    void *waitRear;
    int waitCount;
};

#endif