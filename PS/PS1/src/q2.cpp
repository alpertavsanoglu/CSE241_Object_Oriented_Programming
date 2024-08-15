#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int humanTurn(int humanTotalScore);
int computerTurn(int computerTotalScore);
int roll(int& score);
int main(){

int humanScore=0,computerScore=0;		//Initializing the scores
	do{
		humanScore=humanTurn(humanScore);
		cout<<endl<<"Your Score:"<<humanScore<<endl;
		
		if(humanScore<100){		//Continue to program if human hasnt won already
		computerScore=computerTurn(computerScore);
		cout<<endl<<"Computer Score:"<<computerScore<<endl;}
	}while(humanScore<100 && computerScore<100);//Keep doing till there is a winner

	if(humanScore>=100) cout<<"You won"<<endl;
	if(computerScore>=100) cout<<"You lost"<<endl;

}


int roll(int& score){

	
int a =  rand() % 6 + 1;		//Making it between 1-6
	cout<<a;	
	if(a==1)  score=-1;			//A checkpoint when 1 is entered to let the program know it should stop
	else {
	score+=a;				//Assigning the dice number to the total score at that turn
	};
	return score;
}



int computerTurn(int computerTotalScore){
//Computer Turn Starts
int Score=0;
cout<<"Computer rolls:"<<endl;
	while(1){		//Looping till a rule breaks the loop
cin.ignore();		//Requires an entry to avoid compiler doing it too fast and gives the same results.(like 5 5 5 5)
roll(Score);

if(Score==-1){		//It returns -1 for when 1 is rolled and to let the program know to stop the turn
Score=0;		//Giving it its original value and breaking the loop
break;
}
if(Score>=20){		//Ending the loop if computer scores more than 19
break;}
	}

return Score+computerTotalScore;	//Returns the total score of the computer at that turn
//Computer Turn Ends
}



int humanTurn(int humanTotalScore){
//Human Turn Starts
int score=0;
char opt;
while(opt!='h'){	//Looping till player decides to hold

cout<<endl<<"Press r to roll the dice,h to hold : ";
cin>>opt;
if(opt=='r'){
roll(score);
}
if(score==-1){		//It returns -1 for when 1 is rolled and to let the program know to stop the turn
score=0;		//Giving it its original value and breaking the loop
break;
}


}
return score+humanTotalScore;	//Returns the total score of the player at that turn
//Human Turn Ends
}
