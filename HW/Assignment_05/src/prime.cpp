#include <iostream>
#include "prime.h"
using namespace std;

OptimusPrime::OptimusPrime() : Humanic(0) {}        
//OptimusPrime type is 0,Calling the Humanic class constructor with 0
//Then Humanic class will call Robot class constructor as 0 as its type,and default strength and hp
OptimusPrime::OptimusPrime(int b, int c) : Humanic(0, b, c) {}  
//Calling the humanic constructor with  b and c which will call for robot constructor with b and c
//Robot constructor then will assign 0 to type,b to strength,c to hp
int OptimusPrime::getDamage()
{
    int damage = Humanic::getDamage(); //Running the srand(time) on Robot class before using rand again for this class

    int crit = rand() % 100;

    if (crit < 15)              //Giving a %15 chance to critical damage
        return damage * 2;

    return damage;
}
