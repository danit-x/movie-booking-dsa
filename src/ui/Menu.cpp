#include <iostream>
#include <string>
using namespace std;

#include "Menu.h"
#include "ConsoleIO.h"
#include "../models/Constants.h"

void Menu::run(BookingSystem &system)
{
    int mainChoice;
    int movieId;
    int movieShowIds[MAX_SHOWS];
    int showCount;
    int showId;
    int showChoice;
    int bookingId;
    int row;
    int col;
    int seatsNeeded;
    int answer;
    std::string title;
    std::string name;

    while (1)
    {
        cout << endl;
        ConsoleIO::printDivider();
        cout << "        MOVIE TICKET BOOKING" << endl;
        ConsoleIO::printDivider();
        cout << "1) Book Tickets" << endl;
        cout << "2) Search Movie" << endl;
        cout << "3) View My Booking" << endl;
        cout << "4) Cancel booking" << endl;
        cout << "5) Exit" << endl;

        mainChoice = ConsoleIO::readInt("Enter choice: ", 1, 5);
        ConsoleIO::printDivider();

        if (mainChoice == 1)
        {
            system.listMovies();
            movieId = ConsoleIO::readInt("Enter movie ID: ", 0, MAX_MOVIES - 1);
            if (!system.hasMovie(movieId))
            {
                cout << "Error: Invalid movie ID." << endl;
                ConsoleIO::pause();
                continue;
            }

            showCount = system.listShowsForMovieSorted(movieId, movieShowIds);
            if (showCount == 0)
            {
                ConsoleIO::pause();
                continue;
            }
            showId = ConsoleIO::readInt("Enter show ID: ", 0, MAX_SHOWS - 1);
            if (!system.isShowForMovie(movieId, showId))
            {
                cout << "Error: Show does not belong to selected movie." << endl;
                ConsoleIO::pause();
                continue;
            }

            while (1)
            {
                ConsoleIO::printDivider();
                system.printSeatMap(showId);
                cout << "1) Book Single Seat" << endl;
                cout << "2) Book Group Seats" << endl;
                cout << "3) Join Waitlist" << endl;
                cout << "4) Back" << endl;

                showChoice = ConsoleIO::readInt("Enter choice: ", 1, 4);
                ConsoleIO::printDivider();

                if (showChoice == 1)
                {
                    name = ConsoleIO::readName("Enter customer name: ");
                    row = ConsoleIO::readInt("Enter row (1..10): ", 1, ROWS);
                    col = ConsoleIO::readInt("Enter column (1..12): ", 1, COLS);
                    system.bookSingle(showId, name, row, col);
                    ConsoleIO::pause();
                }
                else if (showChoice == 2)
                {
                    Seat recommended[MAX_SEATS_IN_BOOKING];

                    name = ConsoleIO::readName("Enter customer name: ");
                    seatsNeeded = ConsoleIO::readInt("Enter number of seats: ", 2, MAX_SEATS_IN_BOOKING);

                    if (system.recommendSeats(showId, seatsNeeded, recommended))
                    {
                        cout << "Suggested seats: ";
                        for (int i = 0; i < seatsNeeded; i++)
                        {
                            cout << "(" << (int)recommended[i].r + 1 << "," << (int)recommended[i].c + 1 << ")";
                            if (i < seatsNeeded - 1)
                            {
                                cout << ", ";
                            }
                        }
                        cout << endl;
                        answer = ConsoleIO::readInt("Confirm booking? 1 Yes / 2 No: ", 1, 2);
                        if (answer == 1)
                        {
                            system.bookGroup(showId, name, seatsNeeded);
                        }
                    }
                    else
                    {
                        answer = ConsoleIO::readInt("Not enough seats. Join waitlist? 1 Yes / 2 No: ", 1, 2);
                        if (answer == 1)
                        {
                            system.joinWaitlist(showId, name, seatsNeeded);
                        }
                    }
                    ConsoleIO::pause();
                }
                else if (showChoice == 3)
                {
                    name = ConsoleIO::readName("Enter customer name: ");
                    seatsNeeded = ConsoleIO::readInt("Enter number of seats for waitlist: ", 1, MAX_SEATS_IN_BOOKING);
                    system.joinWaitlist(showId, name, seatsNeeded);
                    ConsoleIO::pause();
                }
                else
                {
                    break;
                }
            }
        }
        else if (mainChoice == 2)
        {
            title = ConsoleIO::readLine("Enter exact movie title: ");
            system.searchMovie(title);
            ConsoleIO::pause();
        }
        else if (mainChoice == 3)
        {
            bookingId = ConsoleIO::readInt("Enter booking ID: ", 0, 1000000);
            system.viewBooking(bookingId);
            ConsoleIO::pause();
        }
        else if (mainChoice == 4)
        {
            bookingId = ConsoleIO::readInt("Enter booking ID: ", 0, 1000000);
            name = ConsoleIO::readName("Enter customer name: ");
            system.cancelBooking(bookingId, name);
            ConsoleIO::pause();
        }
        else if (mainChoice == 5)
        {
            cout << "Exiting system." << endl;
            break;
        }
    }
}
