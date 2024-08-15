#include <iostream>
#include "robot.h"

using namespace std;

Robot::Robot(int a, int b, int c) : type(a), strength(b), hp(c) {}

Robot::Robot(int a) : type(a) {}

int Robot::getDamage()
{
    srand(time(NULL));              //Every child class will call for this function first before making further calculations,so starting the srandtime here
    return (rand() % strength) + 1; //Giving a damage between 1 and strength
}

string Robot::getType()             
{
    switch (type)
    {
    case 0:
        return "optimusprime";
    case 1:
        return "robocop";
    case 2:
        return "roomba";
    case 3:
        return "bulldozer";
    }
    return "unknown";
}

int Robot::getStr() { return strength; }

int Robot::gethp() { return hp; }

void Robot::sethp(int x) { hp = x; }

void Robot::setStr(int x) { strength = x; }

Robot::~Robot(){}           //Pure virtual function created for preventing abstract class object creation
