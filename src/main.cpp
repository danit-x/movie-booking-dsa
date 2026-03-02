#include <iostream>
using namespace std;

#include "data/Store.h"
#include "data/SampleData.h"

int main()
{
    Store store;
    StoreOps::init(store);
    SampleData::load(store);

    cout << "=== MOVIE BOOKING SYSTEM ===" << endl;
    cout << "Cinemas:" << endl;

    for (int i = 0; i < store.cinemaCount; i++)
    {
        cout << store.cinemas[i].id << ". "
             << store.cinemas[i].name
             << " (" << store.cinemas[i].location << ")"
             << endl;
    }

    return 0;
}