#ifndef MOVIE_H
#define MOVIE_H

#include "Constants.h"

struct Movie
{
    int id;
    char title[MAX_TITLE];
    int durationMin;
    char rating[6];
};

#endif