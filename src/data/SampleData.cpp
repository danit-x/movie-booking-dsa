#include "SampleData.h"

void SampleData::load(Store &s)
{

    int c1, c2;
    StoreOps::addCinema(s, "CineWorld", "Colombo", c1);
    StoreOps::addCinema(s, "MegaPlex", "Negombo", c2);

    int m1, m2, m3;
    StoreOps::addMovie(s, "Interstellar", 169, "PG13", m1);
    StoreOps::addMovie(s, "Inception", 148, "PG13", m2);
    StoreOps::addMovie(s, "Avengers", 181, "PG13", m3);

    int s1, s2, s3;
    StoreOps::addShow(s, c1, m1, "2026-03-01 18:30", 1200, s1);
    StoreOps::addShow(s, c1, m2, "2026-03-01 21:00", 1000, s2);
    StoreOps::addShow(s, c2, m3, "2026-03-02 17:00", 900, s3);

    // Pre-book a few seats for demo
    int idx = StoreOps::findShowIndexById(s, s1);
    if (idx != -1)
    {
        s.shows[idx].seats[4][5] = 1;
        s.shows[idx].seats[4][6] = 1;
        s.shows[idx].seats[5][5] = 1;
        s.shows[idx].availableCount -= 3;
    }
}