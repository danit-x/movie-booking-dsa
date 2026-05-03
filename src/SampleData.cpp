#include "SampleData.h"
#include <string>

void SampleData::load(Store &store)
{
    const std::string times[3] = {
        "2026-03-03 10:00",
        "2026-03-03 14:00",
        "2026-03-03 18:00"};

    const std::string titles[MAX_MOVIES] = {
        "Inception",
        "Interstellar",
        "The Dark Knight",
        "Avatar",
        "Titanic",
        "Gladiator",
        "Coco",
        "Frozen",
        "Joker",
        "Dune"};

    const int durations[MAX_MOVIES] = {148, 169, 152, 162, 194, 155, 105, 102, 122, 155};
    const int basePrices[MAX_MOVIES] = {1200, 1400, 1300, 1500, 1250, 1350, 1100, 1000, 1450, 1600};

    int i;
    int t;
    int movieId;

    initStore(store);

    for (i = 0; i < MAX_MOVIES; i++)
    {
        movieId = addMovie(store, titles[i], durations[i]);
        for (t = 0; t < 3; t++)
        {
            addShow(store, movieId, times[t], basePrices[i] + (t * 100));
        }
    }

    store.shows[0].seats[4][5] = 1;
    store.shows[0].seats[4][6] = 1;
    store.shows[0].seats[5][5] = 1;
    store.shows[0].availableCount -= 3;
}
