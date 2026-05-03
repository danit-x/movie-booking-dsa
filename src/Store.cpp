#include "Store.h"
#include <cstring>
#include <string>

void initStore(Store &s)
{
    s.movieCount = 0;
    s.showCount = 0;
    s.bookingCount = 0;

    s.nextMovieId = 0;
    s.nextShowId = 0;
    s.nextBookingId = 0;
}

int addMovie(Store &s, const std::string &title, int durationMin)
{
    if (s.movieCount >= MAX_MOVIES)
        return -1;

    Movie &m = s.movies[s.movieCount];
    m.id = s.nextMovieId++;
    m.durationMin = durationMin;
    m.title = title;

    s.movieCount++;
    return m.id;
}

int addShow(Store &s, int movieId, const std::string &datetime, int price)
{
    if (s.showCount >= MAX_SHOWS)
        return -1;

    Show &sh = s.shows[s.showCount];
    sh.id = s.nextShowId++;
    sh.movieId = movieId;
    sh.datetime = datetime;
    sh.price = price;
    initShowSeats(sh);

    s.showCount++;
    return sh.id;
}

void initShowSeats(Show &show)
{
    show.availableCount = ROWS * COLS;
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            show.seats[r][c] = 0;
        }
    }
}

int findMovieIndexById(const Store &store, int movieId)
{
    for (int i = 0; i < store.movieCount; i++)
    {
        if (store.movies[i].id == movieId)
            return i;
    }
    return -1;
}