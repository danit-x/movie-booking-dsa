#include "Menu.h"
#include "ConsoleIO.h"
#include <iostream>
using namespace std;

void Menu::run(Store &s)
{
    while (true)
    {
        ConsoleIO::printDivider();
        cout << "MOVIE BOOKING SYSTEM (Customer)" << endl;
        cout << "1. List Cinemas" << endl;
        cout << "2. Select Cinema" << endl;
        cout << "3. Exit" << endl;

        int choice = ConsoleIO::readInt("Choose: ", 1, 3);

        if (choice == 1)
            listCinemas(s);
        else if (choice == 2)
            selectCinema(s);
        else
            break;
    }
}

void Menu::listCinemas(Store &s)
{
    ConsoleIO::printDivider();
    cout << "Cinemas:" << endl;

    for (int i = 0; i < s.cinemaCount; i++)
    {
        cout << s.cinemas[i].id << ". "
             << s.cinemas[i].name
             << " (" << s.cinemas[i].location << ")"
             << endl;
    }
    ConsoleIO::pause();
}

void Menu::selectCinema(Store &s)
{
    if (s.cinemaCount == 0)
    {
        cout << "No cinemas available." << endl;
        ConsoleIO::pause();
        return;
    }

    listCinemas(s);
    int id = ConsoleIO::readInt("Enter Cinema ID: ", 1, 999999);

    int idx = StoreOps::findCinemaIndexById(s, id);
    if (idx == -1)
    {
        cout << "Cinema not found." << endl;
        ConsoleIO::pause();
        return;
    }

    ConsoleIO::printDivider();
    cout << "Selected Cinema: " << s.cinemas[idx].name
         << " (" << s.cinemas[idx].location << ")" << endl;

    ConsoleIO::pause();
}