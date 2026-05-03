#ifndef STORE_H
#define STORE_H

#include <string>
#include "../include/Show.h"
#include "../include/Movie.h"
#include "../include/Booking.h"

struct Store
{
    Movie movies[MAX_MOVIES];
    Show shows[MAX_SHOWS];
    Booking bookings[MAX_BOOKINGS];

    int movieCount;
    int showCount;
    int bookingCount;
    int nextMovieId;
    int nextShowId;
    int nextBookingId;
};

void initStore(Store &store);
int addMovie(Store &store, const std::string &title, int durationMin);
int addShow(Store &store, int movieId, const std::string &datetime, int price);
void initShowSeats(Show &show);

int findMovieIndexById(const Store &store, int movieId);

#endif
