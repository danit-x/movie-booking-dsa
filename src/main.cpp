#include "data/Store.h"
#include "data/SampleData.h"
#include "ui/Menu.h"

int main()
{
    Store store;
    StoreOps::init(store);
    SampleData::load(store);

    Menu::run(store);
    return 0;
}