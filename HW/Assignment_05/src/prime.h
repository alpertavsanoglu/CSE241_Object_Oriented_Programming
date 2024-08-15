#ifndef PRIME_H
#define PRIME_H
#include <iostream>
#include "humanic.h"
using namespace std;

class OptimusPrime:public Humanic
{
    public:
    OptimusPrime();
    OptimusPrime(int b,int c);
    int getDamage();


};

#endif
