#include <iostream>
#include "robocop.h"
using namespace std;

Robocop::Robocop():Humanic(1){}

Robocop::Robocop(int b,int c):Humanic(1,b,c){}

int Robocop::getDamage()
{
    return Humanic::getDamage();
}
