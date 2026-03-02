#ifndef MENU_H
#define MENU_H

#include "../data/Store.h"

class Menu
{
public:
    static void run(Store &s);

private:
    static void listCinemas(Store &s);
    static void selectCinema(Store &s);
};

#endif