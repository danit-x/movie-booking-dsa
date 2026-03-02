#ifndef STORE_H
#define STORE_H

#include "../models/Cinema.h"
#include "../models/Movie.h"
#include "../models/Show.h"
#include "../models/Booking.h"

struct Store
{
    Cinema cinemas[MAX_CINEMAS];
    int cinemaCount;

    Movie movies[MAX_MOVIES];
    int movieCount;

    Show shows[MAX_SHOWS];
    int showCount;

    Booking bookings[MAX_BOOKINGS];
    int bookingCount;

    int nextCinemaId;
    int nextMovieId;
    int nextShowId;
    int nextBookingId;
};

class StoreOps
{
public:
    static void init(Store &s);

    static bool addCinema(Store &s, const char *name, const char *location, int &outCinemaId);
    static bool addMovie(Store &s, const char *title, int durationMin, const char *rating, int &outMovieId);
    static bool addShow(Store &s, int cinemaId, int movieId, const char *datetime, int price, int &outShowId);

    static void initShowSeats(Show &sh);
    static int countAvailableSeats(const Show &sh);

    static int findCinemaIndexById(const Store &s, int cinemaId);
    static int findMovieIndexById(const Store &s, int movieId);
    static int findShowIndexById(const Store &s, int showId);
};

#endif