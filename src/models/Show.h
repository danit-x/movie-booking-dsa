#ifndef SHOW_H
#define SHOW_H

#include "Constants.h"

struct Show
{
    int id;
    int cinemaId;
    int movieId;

    char datetime[MAX_DATETIME];
    int price;

    unsigned char seats[ROWS][COLS];
    int availableCount;

    void *bookingIdlistHead;
    void *waitFront;
    void *waitRear;
    int waitCount;
};

#endif