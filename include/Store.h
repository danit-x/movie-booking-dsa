#ifndef STORE_H
#define STORE_H

#include "Show.h"
#include "Movie.h"

struct Store
{
    Show shows[1000];  // Array to store shows
    Movie movies[100]; // Array to store movies
};

#endif
