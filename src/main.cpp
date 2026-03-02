#include <iostream>
using namespace std;

#include "models/Movie.h"

int main()
{
    Movie m;
    m.id = 1;
    cout << "Movie ID: " << m.id << endl;
    return 0;
}