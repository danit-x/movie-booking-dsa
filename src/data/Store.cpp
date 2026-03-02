#include "Store.h"
#include <cstring>

void StoreOps::init(Store &s)
{
    s.cinemaCount = 0;
    s.movieCount = 0;
    s.showCount = 0;
    s.bookingCount = 0;

    s.nextCinemaId = 1;
    s.nextMovieId = 1;
    s.nextShowId = 1;
    s.nextBookingId = 1;
}

bool StoreOps::addCinema(Store &s, const char *name, const char *location, int &outCinemaId)
{
    if (s.cinemaCount >= MAX_CINEMAS)
        return false;

    Cinema &c = s.cinemas[s.cinemaCount];
    c.id = s.nextCinemaId++;

    std::strncpy(c.name, name, MAX_NAME - 1);
    c.name[MAX_NAME - 1] = '\0';

    std::strncpy(c.location, location, MAX_LOC - 1);
    c.location[MAX_LOC - 1] = '\0';

    s.cinemaCount++;
    outCinemaId = c.id;
    return true;
}

bool StoreOps::addMovie(Store &s, const char *title, int durationMin, const char *rating, int &outMovieId)
{
    if (s.movieCount >= MAX_MOVIES)
        return false;

    Movie &m = s.movies[s.movieCount];
    m.id = s.nextMovieId++;

    std::strncpy(m.title, title, MAX_TITLE - 1);
    m.title[MAX_TITLE - 1] = '\0';

    m.durationMin = durationMin;

    std::strncpy(m.rating, rating, 5);
    m.rating[5] = '\0';

    s.movieCount++;
    outMovieId = m.id;
    return true;
}

void StoreOps::initShowSeats(Show &sh)
{
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            sh.seats[r][c] = 0;
        }
    }
    sh.availableCount = ROWS * COLS;
    sh.bookingIdListHead = NULL;
    sh.waitFront = NULL;
    sh.waitRear = NULL;
    sh.waitCount = 0;
}

int StoreOps::countAvailableSeats(const Show &sh)
{
    int count = 0;
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            if (sh.seats[r][c] == 0)
                count++;
        }
    }
    return count;
}

bool StoreOps::addShow(Store &s, int cinemaId, int movieId, const char *datetime, int price, int &outShowId)
{
    if (s.showCount >= MAX_SHOWS)
        return false;

    Show &sh = s.shows[s.showCount];
    sh.id = s.nextShowId++;

    sh.cinemaId = cinemaId;
    sh.movieId = movieId;

    std::strncpy(sh.datetime, datetime, MAX_DATETIME - 1);
    sh.datetime[MAX_DATETIME - 1] = '\0';

    sh.price = price;

    initShowSeats(sh);

    s.showCount++;
    outShowId = sh.id;
    return true;
}

int StoreOps::findCinemaIndexById(const Store &s, int cinemaId)
{
    for (int i = 0; i < s.cinemaCount; i++)
    {
        if (s.cinemas[i].id == cinemaId)
            return i;
    }
    return -1;
}

int StoreOps::findMovieIndexById(const Store &s, int movieId)
{
    for (int i = 0; i < s.movieCount; i++)
    {
        if (s.movies[i].id == movieId)
            return i;
    }
    return -1;
}

int StoreOps::findShowIndexById(const Store &s, int showId)
{
    for (int i = 0; i < s.showCount; i++)
    {
        if (s.shows[i].id == showId)
            return i;
    }
    return -1;
}