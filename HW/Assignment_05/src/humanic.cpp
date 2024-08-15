#include <iostream>
#include "humanic.h"
using namespace std;

Humanic::Humanic(int a) : Robot(a) {}

Humanic::Humanic(int a, int b, int c) : Robot(a, b, c) {}

Humanic::~Humanic() {}

int Humanic::getDamage()
{
    int damage = Robot::getDamage();    //Running the srand(time) on Robot class before using rand again for this class

    int crit = rand() % 10;

    if (crit == 9)                  //Giving a %10 chance to tactical nuke damage
        return damage + 50;

    return damage;
}
