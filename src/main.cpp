#include <iostream>
using namespace std;

#include "../include/BookingSystem.h"
#include "../include/Menu.h"

int main()
{
    BookingSystem system;
    Menu::run(system);
    return 0;
}
