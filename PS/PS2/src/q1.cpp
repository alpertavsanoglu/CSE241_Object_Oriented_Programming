#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void Aaron_turn(bool aaronAlive, bool &bobAlive, bool &charlieAlive);       /*aaron shoot*/
void Bob_turn(bool &aaronAlive, bool bobAlive, bool &charlieAlive);         /*bob shoot*/
void Charlie_turn(bool &aaronAlive, bool &bobAlive, bool charlieAlive);     /*charlie shoot*/
void gameplay(int &aaronWin, int &bobWin, int &charlieWin);                 /*gaming*/
const int NUM_OF_DUELS=1e4;                                                 /*duels*/

int main(){
    srand(time(NULL));
    int aaronWinCount = 0;
    int bobWinCount = 0;
    int charlieWinCount = 0;

    for(int roundNum = 0; roundNum < NUM_OF_DUELS; ++roundNum){         /*playing duels*/
        gameplay(aaronWinCount, bobWinCount, charlieWinCount);
                                                                }       /*duel results*/
cout<< "Aaron won " << aaronWinCount << "/" << NUM_OF_DUELS << " duels or " << aaronWinCount / static_cast<double>(NUM_OF_DUELS) * 100 << "%\n"
    << "Bob won " << bobWinCount << "/" << NUM_OF_DUELS << " duels or " << bobWinCount / static_cast<double>(NUM_OF_DUELS) * 100 << "%\n"
    << "Charlie won " << charlieWinCount << "/" << NUM_OF_DUELS << " duels or " << charlieWinCount / static_cast<double>(NUM_OF_DUELS) * 100 << "%\n";

    return 0;
}
void gameplay(int &aaronWin, int &bobWin, int &charlieWin){     

    bool aaronAlive = true;             /*they are alive*/
    bool bobAlive = true;
    bool charlieAlive = true;
    do{
        Aaron_turn(aaronAlive, bobAlive, charlieAlive);                                                 /*aaron shoot*/
        Bob_turn(aaronAlive, bobAlive, charlieAlive);                                                   /*bob shoot*/
        Charlie_turn(aaronAlive, bobAlive, charlieAlive);                                               /*charlie shoot*/
    }while( (aaronAlive && bobAlive) || (aaronAlive && charlieAlive) || (bobAlive && charlieAlive) );

    if(charlieAlive) ++charlieWin;              /*increase charlie*/
    else if(bobAlive) ++bobWin;                 /*increase bob*/
    else if(aaronAlive) ++aaronWin;             /*increase aaron*/
}
void Charlie_turn(bool &aaronAlive, bool &bobAlive, bool charlieAlive){          /*charlie shoot*/
    
    int turn;
    if(!charlieAlive){          /*if charlie is dead*/
                        return;
                        }
    if(bobAlive){ 
                bobAlive = false;           /*kill bob*/
                }
    else if(aaronAlive){ 
                        aaronAlive = false;     /*kill aaron*/
                        }
return;
}
void Bob_turn(bool &aaronAlive, bool bobAlive, bool &charlieAlive){
    
    if(!bobAlive){              /*if bob is dead*/
                return;
                }
  int turn = !(rand() % 2);     /*bobs rate*/

    if(turn){
        if(charlieAlive){ 
                        charlieAlive = false;       /*kill charlie*/
                        }
        else if(aaronAlive){ 
                            aaronAlive = false;         /*kill aaron*/
                            }
    }
return;
}
void Aaron_turn(bool aaronAlive, bool &bobAlive, bool &charlieAlive){

    if(!aaronAlive){            /*if aaron is dead */
                    return;
                    }

    int turn = !(rand() % 3);           /*aarons rate*/

    if(turn){
        if(charlieAlive){                           
                        charlieAlive = false;            /*kill charlie*/
                        }
        else if (bobAlive){
        bobAlive = false;           /* kill bob */
        }
    }
return;
}
