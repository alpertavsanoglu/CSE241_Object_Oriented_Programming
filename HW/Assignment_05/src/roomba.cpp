#include <iostream>
#include "roomba.h"
using namespace std;

Roomba::Roomba() : Robot(2) {}

Roomba::Roomba(int b, int c) : Robot(2, b, c) {}

int Roomba::getDamage()
{
    return Robot::getDamage() * 2;
}
