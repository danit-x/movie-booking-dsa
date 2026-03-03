#include <iostream>
using namespace std;

#include "app/BookingSystem.h"
#include "ui/Menu.h"

int main()
{
    BookingSystem system;
    Menu::run(system);
    return 0;
}
