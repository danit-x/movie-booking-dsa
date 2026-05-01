#ifndef SEATINGGRID_H
#define SEATINGGRID_H

#include <iostream>
#include "HashTableIntToIndex.h"
#include "SinglyLinkedListInt.h"

using namespace std;

class SeatingGrid
{
public:
    static const int AVAILABLE = 0;
    static const int SELECTED  = 1;
    static const int BOOKED    = 2;

private:
    int **grid;
    int rows;
    int cols;

    HashTableIntToIndex seatMap;
    SinglyLinkedListInt selectedSeats;

    int encodeKey(int row, int col) const;
    int isValid(int row, int col) const;

public:
    SeatingGrid();
    ~SeatingGrid();

    void init(int rows, int cols);

    int selectSeat(int row, int col);
    int deselectSeat(int row, int col);
    int confirmBooking();
    int cancelSeat(int row, int col);
    int isAvailable(int row, int col) const;

    void suggestSeats(int count) const;
    void displayGrid() const;

    int getAvailableCount() const;
    int getSelectedCount() const;
    int getBookedCount() const;
};

#endif