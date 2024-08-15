#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>


using namespace std;


class Robot
{
    public:
    Robot(int a);
    Robot(int a,int b,int c);
    virtual int getDamage();
    string getType();
    int getStr();
    int gethp();
    void setStr(int x);
    void sethp(int x);
    virtual ~Robot()=0;             //Making it abstract
    protected:
    int type;
    int strength;
    int hp;

};


#endif
