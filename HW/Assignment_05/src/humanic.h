#ifndef HUMANIC_H
#define HUMANIC_H
#include <iostream>
#include "robot.h"

using namespace std;

class Humanic : public Robot
{
public:
    Humanic(int a);
    Humanic(int a,int b,int c);
    virtual int getDamage();
    virtual ~Humanic();     //Making it abstract
};

#endif
