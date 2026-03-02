#include "ConsoleIO.h"
#include <iostream>
#include <cstring>
using namespace std;

void ConsoleIO::printDivider()
{
    cout << "----------------------------------------" << endl;
}

void ConsoleIO::pause()
{
    cout << "Press ENTER to continue...";
    cin.ignore(10000, '\n');
    cin.get();
}

int ConsoleIO::readInt(const char *prompt, int minVal, int maxVal)
{
    int x;
    while (true)
    {
        cout << prompt;
        cin >> x;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Try again." << endl;
            continue;
        }

        if (x < minVal || x > maxVal)
        {
            cout << "Out of range. Enter between " << minVal << " and " << maxVal << "." << endl;
            continue;
        }

        cin.ignore(10000, '\n');
        return x;
    }
}

void ConsoleIO::readLine(const char *prompt, char *out, int maxLen)
{
    cout << prompt;
    cin.getline(out, maxLen);
    if (strlen(out) == 0)
    {
        // if user just pressed enter, keep asking
        while (strlen(out) == 0)
        {
            cout << prompt;
            cin.getline(out, maxLen);
        }
    }
}