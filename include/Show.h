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
    int waitCount;
};

#endif