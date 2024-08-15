#ifndef BULL_H
#define BULL_H
#include <iostream>
#include "robot.h"

using namespace std;

class Bulldozer : public Robot
{
public:
    Bulldozer();
    Bulldozer(int b, int c);
    int getDamage();
};

#endif
