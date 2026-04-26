
#include <iostream>
#include <ctime>
#include "UdeaCup.h"

using namespace std;

int main()
{
    srand(time(NULL));

    UdeaCup torneo;
    torneo.menu();

    return 0;
}

