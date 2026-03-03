#ifndef SHOW_H
#define SHOW_H

#include <string>
#include "Constants.h"

struct Show
{
    int id;
    int movieId;
    std::string datetime;
    int price;
    unsigned char seats[ROWS][COLS];
    int availableCount;
    void *bookingIdListHead;
    void *waitFront;
    void *waitRear;
    int waitCount;
};

#endif
