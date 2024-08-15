#ifndef ROOMBA_H
#define ROOMBA_H
#include <iostream>
#include "robot.h"

using namespace std;

class Roomba : public Robot
{
public:
    Roomba();
    Roomba(int b, int c);
    int getDamage();
};

#endif
