#include <iostream>

#include "../include/HashTableIntToIndex.h"

int main()
{
    HashTableIntToIndex table;
    table.init(10);

    table.put(42, 100);
    table.put(7, 200);
    table.put(42, 300); // update existing key

    int value;
    if (table.get(42, value))
    {
        std::cout << "Key 42 => " << value << "\n";
    }
    else
    {
        std::cout << "Key 42 not found\n";
    }

    if (table.get(7, value))
    {
        std::cout << "Key 7 => " << value << "\n";
    }
    else
    {
        std::cout << "Key 7 not found\n";
    }

    if (table.remove(42))
    {
        std::cout << "Removed key 42\n";
    }

    if (table.get(42, value))
    {
        std::cout << "Key 42 => " << value << "\n";
    }
    else
    {
        std::cout << "Key 42 not found after removal\n";
    }

    std::cout << "Table size: " << table.getSize() << "\n";

    table.clear();
    std::cout << "Table size after clear: " << table.getSize() << "\n";

    return 0;
}
