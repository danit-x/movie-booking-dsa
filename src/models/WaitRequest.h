#ifndef WAITREQUEST_H
#define WAITREQUEST_H

#include "Constants.h"

struct WaitRequest
{
    char name[MAX_NAME];
    int seatRequested;
};

#endif