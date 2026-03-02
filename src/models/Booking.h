#ifndef BOOKING_H
#define BOOKING_H

#include "Constants.h"

enum BookingStatus
{
    BOOKING_CONFIRMED = 1,
    BOOKING_CANCELLED = 0
};

struct Booking
{
    int id;
    int showId;
    char customerName[MAX_NAME];

    int seatCount;
    unsigned char seatR[MAX_SEATS_IN_BOOKING];
    unsigned char seatC[MAX_SEATS_IN_BOOKING];

    int status;
};

#endif