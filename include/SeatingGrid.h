#ifndef SEATINGGRID_H
#define SEATINGGRID_H

#include "HashTableIntToIndex.h"
#include "SinglyLinkedListInt.h"

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

    HashTableIntToIndex seatMap;      // maps encoded seat key -> flat index for fast lookup
    SinglyLinkedListInt selectedSeats; // tracks seats the user has currently selected

    int encodeKey(int row, int col) const;
    bool isValid(int row, int col) const;

public:
    SeatingGrid();
    ~SeatingGrid();

    // Call before using. rows max 26 (A-Z), cols max 99.
    void init(int rows, int cols);

    // User picks a seat before confirming
    bool selectSeat(int row, int col);
    bool deselectSeat(int row, int col);

    // Locks all selected seats as booked
    bool confirmBooking();

    // Admin/cancel use
    bool cancelSeat(int row, int col);

    bool isAvailable(int row, int col) const;

    // Graph logic: finds 'count' consecutive available seats in the same row
    void suggestSeats(int count) const;

    void displayGrid() const;

    int getAvailableCount() const;
    int getSelectedCount() const;
    int getBookedCount() const;

    SeatingGrid(const SeatingGrid &) = delete;
    SeatingGrid &operator=(const SeatingGrid &) = delete;
};

#endif