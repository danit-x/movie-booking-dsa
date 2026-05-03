#ifndef SHOW_H
#define SHOW_H

#include <string>
#include "Constants.h"
#include "SinglyLinkedListInt.h"
#include "QueueArrayWait.h"

struct Show
{
    int id;
    int movieId;
    std::string datetime;
    int price;
    unsigned char seats[ROWS][COLS];
    int availableCount;
    int waitCount;
    SinglyLinkedListInt::Node *bookingIdListHead;
    QueueArrayWait *waitFront;
    QueueArrayWait *waitRear;
};

#endif
