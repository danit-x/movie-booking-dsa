#include <iostream>
#include <string>
using namespace std;

#include "ConsoleIO.h"

int ConsoleIO::readInt(const std::string &prompt, int minValue, int maxValue)
{
    int value;

    while (1)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid integer." << endl;
            continue;
        }

        cin.ignore(10000, '\n');

        if (value < minValue || value > maxValue)
        {
            cout << "Error: Please enter a value between " << minValue << " and " << maxValue << "." << endl;
            continue;
        }

        return value;
    }
}

std::string ConsoleIO::readLine(const std::string &prompt)
{
    std::string input;
    while (1)
    {
        cout << prompt;
        std::getline(cin, input);

        if (input.empty())
        {
            cout << "Error: Input cannot be empty." << endl;
            continue;
        }
        return input;
    }
}

std::string ConsoleIO::readName(const std::string &prompt)
{
    return readLine(prompt);
}

void ConsoleIO::printDivider()
{
    cout << "----------------------------------------" << endl;
}

void ConsoleIO::pause()
{
    std::string dummy;
    cout << "Press Enter to continue...";
    std::getline(cin, dummy);
}
