#include <iostream>
using namespace std;

#include "BookingSystem.h"
#include "Menu.h"

int main()
{
    BookingSystem system;
    Menu::run(system);
    return 0;
}
