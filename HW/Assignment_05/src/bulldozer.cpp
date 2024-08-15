#include <iostream>
#include "bulldozer.h"
using namespace std;

Bulldozer::Bulldozer() : Robot(3) {  } 

Bulldozer::Bulldozer(int b, int c) : Robot(3, b, c) {  }

int Bulldozer::getDamage()
{
    return Robot::getDamage();
}
