#ifndef ROBOCOP_H
#define PRIME_H
#include <iostream>
#include "humanic.h"
using namespace std;

class Robocop:public Humanic
{
    public:
    Robocop();
    Robocop(int b,int c);
    int getDamage();

};

#endif
