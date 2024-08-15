#include <iostream>
#include "bulldozer.h"
#include "robot.h"
#include "prime.h"
#include "robocop.h"
#include "roomba.h"
#include "humanic.h"

using namespace std;

void match(Robot &r1, Robot &r2)             //Match between 2 robot ref's
{

    cout << "Simulation between " << r1.getType() << " and " << r2.getType() << " starts." << endl;

    while (1)
    {     //Both robots hit each other at the same time.Which means they can both die at the same round.
        int dmg = r1.getDamage();                 //Damage of first robot
        int damage = r2.getDamage();              //Damage of second robot
        r1.sethp(r1.gethp() - damage);            //Inflicting damages
        r2.sethp(r2.gethp() - dmg);

        cout << "Robot-1 inflicted " << dmg << " damage " << endl
             << "Robot-2 inflicted " << damage << " damage " << endl;
        cout << "Robot-1's HP : " << r1.gethp() << endl
             << "Robot-2's HP is " << r2.gethp() << endl;
        if (r1.gethp() <= 0 && r2.gethp() <= 0)
        {
            cout << "Both robots are dead.There is no winner" << endl
                 << endl;
            break;
        }
        if (r1.gethp() <= 0)
        {
            cout << "The winner is Robot-1: " << r2.getType() << endl //Printing "Robot-X and their type" in case of a match between same types
                 << endl;
            break;
        }
        if (r2.gethp() <= 0)
        {
            cout << "The winner is Robot-2:" << r1.getType() << endl
                 << endl;
            break;
        }
        cout << endl
             << "Press enter to continue the simulation" << endl;
        getchar();       //Waiting for user to press enter
    }
}

int main()
{
     //TEST
    OptimusPrime prime(10, 50);
    Roomba roomba(20, 50);
    Bulldozer buldozer(40,40);
    Robocop robocop(30 ,50);
    match(prime, roomba);
  //match(buldozer, roomba);
  //match(robocop, roomba);
  //match(prime, buldozer);
  //match(prime, robocop);
  //match(buldozer,robocop );  
    // Random GetDamage's
    cout 	//<< "Bulldozer damage : " << buldozer.getDamage() << endl
         	//<< "Robocop damage : " << robocop.getDamage() << endl
         	<< "Roomba damage " << roomba.getDamage() << endl
         	<< "OptimusPrime damage : " << prime.getDamage() << endl;
}
